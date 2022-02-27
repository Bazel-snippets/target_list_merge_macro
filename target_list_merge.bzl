# buildifier: disable=module-docstring
load("//:targets.bzl", "subsets_dict")
load("@bazel_skylib//lib:new_sets.bzl", "sets")
load("@bazel_skylib//rules:common_settings.bzl", "BuildSettingInfo")

CombinedTargetSetInfo = provider("", fields = {
    "target_set": "set of targets",
})

def _target_list_merge_rule_impl(ctx):
    # print(dir(ctx.attr))
    subsets = ctx.attr._subsets[BuildSettingInfo].value
    combined_target_set = sets.make([])
    set_names = subsets_dict.keys()
    for set in set_names:
        if set in subsets:
            current_set = getattr(ctx.attr, "targets_%s" % set)
            combined_target_set = sets.union(combined_target_set, sets.make(current_set))

    print("combined_target_set = %s" % sets.to_list(combined_target_set))
    return CombinedTargetSetInfo(target_set = combined_target_set)

# buildifier: disable=function-docstring
def generate_target_list_merge_rule_definition():
    attrs = {}
    set_names = subsets_dict.keys()
    for set in set_names:
        attrs["targets_" + set] = attr.label_list()

    attrs["additional_targets"] = attr.label_list()
    attrs["_subsets"] = attr.label(default = "subsets")

    target_list_merge_rule = rule(
        implementation = _target_list_merge_rule_impl,
        attrs = attrs,
    )
    return target_list_merge_rule

target_list_merge_rule = generate_target_list_merge_rule_definition()

# buildifier: disable=function-docstring
def generate_target_list_merge_rule_invocation():
    attrs = {}
    set_names = subsets_dict.keys()
    for set in set_names:
        attrs["targets_" + set] = _targets_selector(set)

    target_list_merge_rule(
        name = "target_list_merge",
        # The target(s) instantiated by this rule are NOT only for building tests, but they MUST be
        # marked as "testonly" so Bazel will permit them to depend upon other test-only targets.
        testonly = True,
        **attrs,
    )

# buildifier: disable=function-docstring
# buildifier: disable=unnamed-macro
def _targets_selector(set_name):
    set_name = set_name.lower()
    build_types = subsets_dict[set_name].keys()
    select_dict = {}
    for build_type in build_types:
        build_type = build_type.lower()
        condition = build_type # "@tab_toolchains//conditions:" +
        selected_targets = list(subsets_dict[set_name][build_type])
        select_dict[condition] = selected_targets

    select_dict["//conditions:default"] = []
    # print("select_dict = %s" % select_dict)
    return select(select_dict)
