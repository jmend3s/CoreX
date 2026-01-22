
#include "Gpio.h"
#include "FakeHalGpio.h"

#include <gtest/gtest.h>


class GpioTestFixture : public ::testing::Test
{
public:
    GpioTestFixture()
        : spec { reinterpret_cast<uintptr_t>(&state) }
        , gpio { spec, Gpio::Mode::Output }
    {
        gpio.configure();
    }

protected:
    FakeGpioState state;
    GpioSpec spec;
    Gpio gpio;
};


TEST_F(GpioTestFixture, GpioConfigures)
{
    EXPECT_TRUE(state.configured);
    EXPECT_TRUE(state.outputMode);
}

TEST_F(GpioTestFixture, GpioOutputs)
{
    gpio.set(Gpio::State::High);
    EXPECT_TRUE(state.level);

    gpio.set(Gpio::State::Low);
    EXPECT_FALSE(state.level);

    EXPECT_EQ(state.setCalls, 2);
}

TEST_F(GpioTestFixture, GpioToggles)
{
    gpio.set(Gpio::State::High);
    EXPECT_TRUE(state.level);

    gpio.toggle();
    EXPECT_FALSE(state.level);

    gpio.toggle();
    EXPECT_TRUE(state.level);

    EXPECT_EQ(state.toggleCalls, 2);
}

TEST_F(GpioTestFixture, GpioRead)
{
    gpio.set(Gpio::State::Low);

    EXPECT_FALSE(state.level);
    EXPECT_EQ(gpio.read(), Gpio::State::Low);

    gpio.set(Gpio::State::High);

    EXPECT_TRUE(state.level);
    EXPECT_EQ(gpio.read(), Gpio::State::High);
}
