
add_executable(corekitTests)

target_sources(corekitTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/corekit/components/Timer.cpp
        ${CMAKE_SOURCE_DIR}/corekit/drivers/Gpio.cpp
        ${CMAKE_SOURCE_DIR}/corekit/drivers/Pwm.cpp
        ${CMAKE_SOURCE_DIR}/corekit/services/TimerService.cpp
        ${CMAKE_SOURCE_DIR}/corekit/scheduler/Scheduler.cpp
        ${CMAKE_SOURCE_DIR}/corekit/system/System.cpp
        ${CMAKE_SOURCE_DIR}/corekit/system/SystemClock.cpp
        ${CMAKE_SOURCE_DIR}/corekit/system/TickCounter.cpp
        ${CMAKE_SOURCE_DIR}/corekit/tests/FakeSystemTime.cpp
        ${CMAKE_SOURCE_DIR}/corekit/tests/hal/FakeHalGpio.cpp
        ${CMAKE_SOURCE_DIR}/corekit/tests/hal/FakeHalPwm.cpp
)

add_subdirectory(integration)
add_subdirectory(testcomponent)
add_subdirectory(unit)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(corekitTests PRIVATE UNICODE _UNICODE)

target_include_directories(corekitTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/corekit/components/
        ${CMAKE_SOURCE_DIR}/corekit/core/
        ${CMAKE_SOURCE_DIR}/corekit/drivers/
        ${CMAKE_SOURCE_DIR}/corekit/hal/
        ${CMAKE_SOURCE_DIR}/corekit/services/
        ${CMAKE_SOURCE_DIR}/corekit/system/
        ${CMAKE_SOURCE_DIR}/corekit/tests/
        ${CMAKE_SOURCE_DIR}/corekit/tests/hal
)

target_link_libraries(corekitTests
    PRIVATE
        GTest::gmock_main
)

gtest_discover_tests(corekitTests)
