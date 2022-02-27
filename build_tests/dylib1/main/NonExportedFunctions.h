/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib1\CMakeFiles\dylib1_obj.dir\main\ExportedFunctions.cpp*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib1\CMakeFiles\dylib1_obj.dir\main\NonExportedFunctions.cpp*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib1*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2*
        tableau-1.3\build\#BUILD_TYPE#-x64\executable*
    </files>

    <files should_change="no" platform="windows">
        tableau-1.3\build\#BUILD_TYPE#-x64\executable*
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib1.lib
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2*
    </files>
*/
// clang-format on

#pragma once

#include "dll/Dylib1Exports.h"

namespace Dylib1
{
    namespace NonExportedFunctions
    {
        int function1();
        int function2();
    }
}
