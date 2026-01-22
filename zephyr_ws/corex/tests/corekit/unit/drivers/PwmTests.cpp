
#include "Pwm.h"
#include "FakeHalPwm.h"

#include <gtest/gtest.h>


class PwmTestFixture : public ::testing::Test
{
public:
    PwmTestFixture()
        : spec { reinterpret_cast<uintptr_t>(&state) }
        , pin { spec }
    {
    }

protected:
    FakePwmState state;
    PwmSpec spec;
    Pwm pin;
};


TEST_F(PwmTestFixture, SetPulseNs)
{
    EXPECT_TRUE(pin.setPulseNs(1'500'000));

    EXPECT_EQ(state.pulse_ns, 1'500'000);
    EXPECT_EQ(state.setPulseCalls, 1);
}

TEST_F(PwmTestFixture, SetPulseUs)
{
    EXPECT_TRUE(pin.setPulseUs(1500));

    EXPECT_EQ(state.pulse_ns, 1'500'000);
    EXPECT_EQ(state.setPulseCalls, 1);
}

TEST_F(PwmTestFixture, SetDutyCycle)
{
    state.period_ns = 20'000'000;

    EXPECT_TRUE(pin.setDutyCycle(0.5f));

    EXPECT_EQ(state.pulse_ns, 10'000'000u);
}

TEST_F(PwmTestFixture, DutyCycleClampsLow)
{
    pin.setDutyCycle(-1.0f);
    EXPECT_EQ(state.pulse_ns, 0);
}

TEST_F(PwmTestFixture, DutyCycleClampsHigh)
{
    pin.setDutyCycle(2.0f);
    EXPECT_EQ(state.pulse_ns, state.period_ns);
}

TEST_F(PwmTestFixture, PeriodIsReadFromHal)
{
    state.period_ns = 1'000'000;
    EXPECT_EQ(pin.periodNs(), 1'000'000);
}
