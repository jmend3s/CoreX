
#include "SystemClock.h"
#include "TickCounter.h"

#include <gtest/gtest.h>


TEST(SystemClockTests, SystemClockBindsToCounter)
{
    TickCounter counter;
    SystemClock::bind(&counter);

    EXPECT_EQ(SystemClock::currentTick(), 0);
}

TEST(SystemClockTests, SystemClockReturnsRightNowTick)
{
    TickCounter counter;
    SystemClock::bind(&counter);

    counter.advance();

    EXPECT_EQ(SystemClock::currentTick(), 1);
}
