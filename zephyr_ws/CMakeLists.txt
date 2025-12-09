
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(corex)

target_link_libraries(app PRIVATE CoreKit)

add_subdirectory(corekit)
add_subdirectory(corex)
