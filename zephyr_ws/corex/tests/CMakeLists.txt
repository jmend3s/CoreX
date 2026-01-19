
cmake_minimum_required(VERSION 3.20.0)

project(corekit_tests)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip # v1.15.2
    URL_HASH SHA256=8C0CEAFA3EA24BF78E3519B7846D99E76C45899AA4DAC4D64E7DD62E495DE9FD
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
set(googletest_targets gtest gtest_main gmock gmock_main)
foreach(googletest_target IN LISTS googletest_targets)
    set_property(TARGET ${googletest_target} PROPERTY FOLDER GoogleTest)
    target_compile_definitions(${googletest_target}
        PRIVATE
            GTEST_CREATE_SHARED_LIBRARY=0
    )
endforeach()

add_subdirectory(corekit)
