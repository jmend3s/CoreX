
target_sources(corekitTests
    PRIVATE
        SchedulerTestsFixture.cpp
        SystemClockTests.cpp
        TickCounterTests.cpp
        TimerServiceTests.cpp
        TimerTests.cpp
)

add_subdirectory(drivers)
