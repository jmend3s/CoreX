
#include "TimerService.h"
#include "TickCounter.h"
#include "SystemClock.h"

#include "gtest/gtest.h"


class TimerServiceTest : public ::testing::Test
{
public:
    TimerServiceTest()
    {
        SystemClock::bind(&_tickCounter);
    }

    void SetUp() override
    {
        _tickCounter.reset();
        _timer.initialize();
    }

protected:
    TimerService _timer;
    TickCounter _tickCounter;
};


TEST_F(TimerServiceTest, TimerServiceInitializesLocked)
{
    EXPECT_FALSE(_timer.ms1());
    EXPECT_FALSE(_timer.ms10());
    EXPECT_FALSE(_timer.ms20());
    EXPECT_FALSE(_timer.ms100());
    EXPECT_FALSE(_timer.ms1000());
}

TEST_F(TimerServiceTest, TimerTriggers)
{
    for (int i = 0; i < 10; i++)
    {
        _tickCounter.advance();
        _timer.update();
    }

    EXPECT_TRUE(_timer.ms1());
}

TEST_F(TimerServiceTest, TimerDoesNotStayElapsed)
{
    for (int i = 0; i < 10; i++)
    {
        _tickCounter.advance();
        _timer.update();
    }

    EXPECT_TRUE(_timer.ms1());

    _timer.update();
    EXPECT_FALSE(_timer.ms1());
}

TEST_F(TimerServiceTest, TimerServiceResetsProperly)
{
    EXPECT_FALSE(_timer.ms1());

    uint32_t constexpr ticksToExpire = 10;
    for (int i = 0; i <= ticksToExpire; i++)
    {
        _tickCounter.advance();
    }
    _timer.update();
    EXPECT_TRUE(_timer.ms1());

    _timer.initialize();
    EXPECT_FALSE(_timer.ms1());
}

TEST_F(TimerServiceTest, TimerServiceClocksUpdate)
{
    struct TestCases
    {
        std::function<bool()> timer;
        uint32_t tickBeforeElapsed;
    };

    std::array<TestCases, 5> testCases {
    {
        { [this] { return _timer.ms1(); }, 9 },
        { [this] { return _timer.ms10(); }, 99 },
        { [this] { return _timer.ms20(); }, 199 },
        { [this] { return _timer.ms100(); }, 999 },
        { [this] { return _timer.ms1000(); }, 9999 },
    }};

    for (auto const& [timer, tickBeforeElapsed] : testCases)
    {
        for (int i = 0; i <= tickBeforeElapsed; i++)
        {
            EXPECT_FALSE(timer());
            _tickCounter.advance();
            _timer.update();
        }

        EXPECT_TRUE(timer());

        _timer.initialize();
    }
}
