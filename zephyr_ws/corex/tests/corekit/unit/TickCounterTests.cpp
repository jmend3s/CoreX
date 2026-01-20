
#include "TickCounter.h"

#include <gtest/gtest.h>


TEST(TickCounterTests, TickCounterInitializesAtZeroTicks)
{
    TickCounter constexpr counter;
    EXPECT_EQ(counter.now(), 0);
}

TEST(TickCounterTests, TickCounterCountsTicksAsItAdvances)
{
    TickCounter counter;

    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(counter.now(), i);
        counter.advance();
    }
}

TEST(TickCounterTests, TickCounterResetsToZero)
{
    TickCounter counter;

    counter.advance();
    counter.reset();
    EXPECT_EQ(counter.now(), 0);
}
