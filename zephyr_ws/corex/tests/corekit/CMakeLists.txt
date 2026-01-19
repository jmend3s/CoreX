
add_executable(corekitTests)

target_sources(corekitTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/corekit/system/Scheduler.cpp
        ${CMAKE_SOURCE_DIR}/corekit/system/TickCounter.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/components/TimerTick.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/core/SchedulableComponent.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/services/TimerService.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/system/Scheduler.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/system/System.cpp
##        ${CMAKE_SOURCE_DIR}/corekit/system/SystemClock.cpp
##        ${CMAKE_SOURCE_DIR}/corekit/system/SystemSleep.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/system/SystemTime.cpp
#        ${CMAKE_SOURCE_DIR}/corekit/tests/SystemTestFixture.cpp
)

#add_subdirectory(mocks)
add_subdirectory(unit)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(corekitTests PRIVATE UNICODE _UNICODE)

target_include_directories(corekitTests
    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/mocks
        ${CMAKE_SOURCE_DIR}/corekit/components/
        ${CMAKE_SOURCE_DIR}/corekit/core/
        ${CMAKE_SOURCE_DIR}/corekit/drivers/
        ${CMAKE_SOURCE_DIR}/corekit/services/
        ${CMAKE_SOURCE_DIR}/corekit/system/
        ${CMAKE_SOURCE_DIR}/corekit/tests/
)

target_link_libraries(corekitTests
    PRIVATE
#        DeviceManagerLib
        GTest::gmock_main
)

gtest_discover_tests(corekitTests)
