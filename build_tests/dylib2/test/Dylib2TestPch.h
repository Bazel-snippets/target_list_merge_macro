/*
    This block is parsed by tools/python/tests/incremental_build_tests/incremental_build_tests.py and
    it defines the files that are expected to be rebuilt when this file has been touched or modified.
    See https://mytableau.tableaucorp.com/display/devft/Incremental+Build+Tests for format.

    <files should_change="yes">
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\CMakeFiles\dylib2_test_obj.dir\test\*
        build\x64\#BUILD_TYPE#\tableau\modules\build_tests\dylib2\test_dylib2.*
        tableau-1.3\build\#BUILD_TYPE#-x64\test_dylib2*
    </files>

    <files should_change="yes" platform="linux">
        tableau-1.3\build\#BUILD_TYPE#-x64\dylib2_syms.map
    </files>
*/
// clang-format on

#pragma once

#include "Dylib2Pch.h"
