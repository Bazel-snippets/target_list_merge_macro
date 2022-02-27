/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib1\CMakeFiles\dylib1_obj.dir\main\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_obj.dir\main\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_test_obj.dir\test\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\executable\CMakeFiles\executable_obj.dir\main\*
        tableau-1.3\build\#BUILD_TYPE#-x64\executable*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib1*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2*
    </files>

    <files should_change="yes" platform="linux">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\*dylib2.pch*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\executable\executable.pch*
    </files>

    <files should_change="yes" platform="windows">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\*dylib2.pch
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\executable\executable.pch
    </files>

    <files should_change="no" platform="windows">
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib1.lib
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib2.lib
    </files>
*/
// clang-format on

#pragma once

#include "dll/Dylib1Exports.h"

namespace Dylib1
{
    namespace ExportedFunctions
    {
        TBL_DYLIB1_EXPORT int function1();
    }
}
