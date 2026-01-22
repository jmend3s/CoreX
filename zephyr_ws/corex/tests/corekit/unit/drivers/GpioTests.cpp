
#include "Gpio.h"
#include "FakeHalGpio.h"

#include <gtest/gtest.h>


class GpioTestFixture : public ::testing::Test
{
public:
    GpioTestFixture()
        : spec { reinterpret_cast<uintptr_t>(&state) }
        , pin { spec, Gpio::Mode::Output }
    {
        pin.configure();
    }

protected:
    FakeGpioState state;
    GpioSpec spec;
    Gpio pin;
};


TEST_F(GpioTestFixture, GpioConfigures)
{
    EXPECT_TRUE(state.configured);
    EXPECT_TRUE(state.outputMode);
}

TEST_F(GpioTestFixture, GpioOutputs)
{
    pin.set(Gpio::State::High);
    EXPECT_TRUE(state.level);

    pin.set(Gpio::State::Low);
    EXPECT_FALSE(state.level);

    EXPECT_EQ(state.setCalls, 2);
}

TEST_F(GpioTestFixture, GpioToggles)
{
    pin.set(Gpio::State::High);
    EXPECT_TRUE(state.level);

    pin.toggle();
    EXPECT_FALSE(state.level);

    pin.toggle();
    EXPECT_TRUE(state.level);

    EXPECT_EQ(state.toggleCalls, 2);
}

TEST_F(GpioTestFixture, GpioRead)
{
    pin.set(Gpio::State::Low);

    EXPECT_FALSE(state.level);
    EXPECT_EQ(pin.read(), Gpio::State::Low);

    pin.set(Gpio::State::High);

    EXPECT_TRUE(state.level);
    EXPECT_EQ(pin.read(), Gpio::State::High);
}
