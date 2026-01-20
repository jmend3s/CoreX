
#include "Timer.h"

#include <gtest/gtest.h>


TEST(TimerTests, TimerStartsLocked)
{
    Timer const timer(1);

    EXPECT_FALSE(timer.elapsed());
}

TEST(TimerTests, TimerUpdatesCorrectly)
{
    Timer timer(2);

    timer.update(1);
    EXPECT_FALSE(timer.elapsed());

    timer.update(1);
    EXPECT_FALSE(timer.elapsed());

    timer.update(2);
    EXPECT_TRUE(timer.elapsed());
}

TEST(TimerTests, TimerResets)
{
    Timer timer(1);

    timer.update(1);
    EXPECT_TRUE(timer.elapsed());

    timer.reset(1);
    EXPECT_FALSE(timer.elapsed());
}
