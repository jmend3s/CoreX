//
// #include "TickCounter.h"
// #include "TimerService.h"
// #include "SchedulableComponent.h"
// #include "System.h"
// #include "SystemTestFixture.h"
//
// #include "gtest/gtest.h"
//
//
// class TimerServiceTest : public ::testing::Test
// {
// protected:
//     TimerService timer;
//
//     SchedulableComponent* components[1] = { &timer };
//     uint64_t tickStorage[1];
//     System system { components, tickStorage, 1 };
//     SystemTestFixture systemTest { system };
//
//     void SetUp() override
//     {
//         systemTest.initialize();
//     }
// };
//
// TEST_F(TimerServiceTest, FiresAfter1000Ticks)
// {
//     systemTest.step(999);
//     EXPECT_FALSE(timer.ms1000());
//
//     systemTest.step(1);
//     EXPECT_TRUE(timer.ms1000());
// }