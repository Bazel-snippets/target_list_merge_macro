/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_obj.dir\main\NonExportedFunctions.cpp*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2*
    </files>

    <files should_change="no" platform="windows">
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2.lib
    </files>
*/
// clang-format on

#include "Dylib2Pch.h" // includes dylib1/ExportedFunctions.h
#include "NonExportedFunctions.h"
#include "dylib2/ExportedFunctions.h"

int Dylib2::NonExportedFunctions::function1()
{
    const auto foo = ::Dylib1::ExportedFunctions::function1();
    const auto bar = ::Dylib2::ExportedFunctions::function1();
    return foo + bar;
}

int Dylib2::NonExportedFunctions::function2()
{
    return 64738; // Long live the C=64!
}
