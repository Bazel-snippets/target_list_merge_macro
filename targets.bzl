subsets_dict = {
    "subset1": {
        "windows": [
            "@//build_tests/dylib1",
            # "@//build_tests/dylib2",
        ],
        "linux": ["@//build_tests/executable:bin"],
    },
    "subset2": {
        "windows": [
            # "@//platform/tabcoredata",
            "@//build_tests/dylib1",
            "@//build_tests/dylib2",
        ],
        "linux": ["@//build_tests/executable"],
    },
}

additional_targets = []