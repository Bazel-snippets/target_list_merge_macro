/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_obj.dir\main\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_test_obj.dir\test\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\*dylib2*
        tableau-1.3\build\#BUILD_TYPE#-x64\*dylib2*
    </files>

    <files should_change="no" platform="osx">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\*dylib2*
    </files>

    <files should_change="no" platform="windows">
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib2.lib
    </files>
*/
// clang-format on

#pragma once

#if defined(BUILD_WINDOWS)
#    pragma warning(disable : 4512) // 'class' : assignment operator could not be generated
#    ifndef WIN32_LEAN_AND_MEAN
#        define WIN32_LEAN_AND_MEAN
#    endif
#    include <windows.h>
#endif // BUILD_WINDOWS

#include "dll/Dylib2Exports.h"
#include "dylib1/ExportedFunctions.h"
#include <memory>
