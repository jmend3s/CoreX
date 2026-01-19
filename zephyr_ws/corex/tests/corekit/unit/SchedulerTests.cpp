
#include "Scheduler.h"
#include "TickCounter.h"

#include <gtest/gtest.h>


class TestComponent : public SchedulableComponent
{
public:
    void initialize() override { init = true; }
    void update() override { _currentUpdateTurn += 1; }
    uint32_t periodTick() const override { return period; }

    uint32_t currentTick() const { return _currentUpdateTurn; }
    bool initialized() const { return init; }

    uint32_t period;

private:
    bool init = false;
    uint32_t _currentUpdateTurn = 0;
};

class SchedulerTests : public ::testing::Test
{
public:
    SchedulerTests()
        : _components{ &_component1, &_component2, &_component3 }
        , _scheduler(_components, _lastTickStorage, _count, _tickCounter)
    {
        _component1.period = 1;
        _component2.period = 2;
        _component3.period = 3;
    }

    void SetUp() override
    {
        _scheduler.initialize();
    }

protected:
    TestComponent _component1;
    TestComponent _component2;
    TestComponent _component3;

    size_t _count = 3;
    uint64_t _lastTickStorage[3] = {};
    SchedulableComponent* _components[3];
    TickCounter _tickCounter;
    Scheduler _scheduler;
};


TEST_F(SchedulerTests, SchedulerInitialization)
{
    std::array<TestComponent*, 3> const components { { &_component1, &_component2, &_component3 } };

    for (int i = 0; i < 3; i++)
    {
        ASSERT_TRUE(components[i]->initialized());
        ASSERT_EQ(components[i]->currentTick(), 0);
        ASSERT_EQ(_lastTickStorage[i], 0);
    }
}

TEST_F(SchedulerTests, DoesNotUpdateBeforePeriod)
{
    _scheduler.runOnce();

    std::array<TestComponent*, 3> const components { { &_component1, &_component2, &_component3 } };
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(components[i]->currentTick(), 0);
        ASSERT_EQ(_lastTickStorage[i], 0);
    }
}

TEST_F(SchedulerTests, DoesNotUpdateTwiceOnSameTick)
{
    _tickCounter.advance();
    _scheduler.runOnce();
    _scheduler.runOnce();

    ASSERT_EQ(_component1.currentTick(), 1);
}

TEST_F(SchedulerTests, HandlesTickJumpCorrectly)
{
    _tickCounter.advance();
    _tickCounter.advance();
    _tickCounter.advance();
    _tickCounter.advance();
    _scheduler.runOnce();

    EXPECT_EQ(_component1.currentTick(), 1);
    EXPECT_EQ(_component2.currentTick(), 1);
    EXPECT_EQ(_component3.currentTick(), 1);
}

TEST_F(SchedulerTests, UpdatesComponentsAccordingToPeriodTicks)
{
    struct TestCase
    {
        int caseNumber;
        uint32_t currentTick1; uint32_t currentTick2; uint32_t currentTick3;
        uint64_t lastTick1; uint64_t lastTick2; uint64_t lastTick3;
    };

    std::array<TestCase, 3> constexpr tests {
    {
        {
            1,
            1, 0, 0,
            1, 0, 0
        },
        {
            2,
            2, 1, 0,
            2, 2, 0
        },
        {
            3,
            3, 1, 1,
            3, 2, 3
        }
    }};

    for (auto const& test : tests)
    {
        _tickCounter.advance();
        _scheduler.runOnce();

        ASSERT_EQ(_component1.currentTick(), test.currentTick1) << "Test case: " << test.caseNumber;
        ASSERT_EQ(_component2.currentTick(), test.currentTick2) << "Test case: " << test.caseNumber;;
        ASSERT_EQ(_component3.currentTick(), test.currentTick3) << "Test case: " << test.caseNumber;;

        ASSERT_EQ(_lastTickStorage[0], test.lastTick1) << "Test case: " << test.caseNumber;;
        ASSERT_EQ(_lastTickStorage[1], test.lastTick2) << "Test case: " << test.caseNumber;;
        ASSERT_EQ(_lastTickStorage[2], test.lastTick3) << "Test case: " << test.caseNumber;;
    }
}
