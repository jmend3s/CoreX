
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(pwm_example)

target_sources(app PRIVATE main.cpp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../../../corekit corekit_build)
target_link_libraries(app PRIVATE corekit)
