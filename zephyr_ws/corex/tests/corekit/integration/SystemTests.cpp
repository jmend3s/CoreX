
#include "../testcomponent/TestComponent.h"

#include "System.h"
#include "FakeSystemTime.h"

#include <gtest/gtest.h>


class SystemTestFixture : public ::testing::Test
{
public:
    SystemTestFixture()
        : _components { &_component }
        , _tickStorage { 0 }
        , _count(1)
        , _system(_components, _tickStorage, _count, _time)
    {
        _component.setUpdatePeriod(1);
    }

    void SetUp() override
    {
        _system.initialize();
    }

protected:
    TestComponent _component;

    SchedulableComponent* _components[1];
    uint64_t _tickStorage[1];
    size_t _count;

    FakeSystemTime _time;
    System _system;
};


TEST_F(SystemTestFixture, AdvancesTickAndRunsScheduler)
{
    for (int i = 0; i < 5; i++)
    {
        _system.runOnce();
        EXPECT_EQ(_component.currentTick(), i);
    }
}
