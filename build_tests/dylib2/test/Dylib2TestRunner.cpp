/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_test_obj.dir\test\Dylib2TestRunner.cpp*
        tableau-1.3\build\#BUILD_TYPE#-x64\test_dylib2*
    </files>

    <files should_change="yes" platform="linux">
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib2_syms.map
    </files>
*/
// clang-format on

#include "Dylib2TestPch.h"
#include "NonExportedFunctions.h"
#include "dylib2/ExportedFunctions.h"

int main()
{
    // We need to allocate some memory here to pass Linux security checks.
    std::unique_ptr<const int> foo(new const int(::Dylib2::ExportedFunctions::function1()));
    std::unique_ptr<const int> bar(new const int(::Dylib2::NonExportedFunctions::function1()));
    std::unique_ptr<const int> baz(new const int(::Dylib2::NonExportedFunctions::function2()));
#if defined(__clang__)
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wunused-variable"
#endif
    const auto throwAway = *foo + *bar + *baz;
#if defined(__clang__)
#    pragma clang diagnostic pop
#endif
    return 0;
}
