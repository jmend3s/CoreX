
#include "Adc.h"
#include "FakeHalAdc.h"

#include <gtest/gtest.h>


class AdcTestFixture : public ::testing::Test
{
public:
    AdcTestFixture()
        : spec { reinterpret_cast<uintptr_t>(&state) }
        , adc { spec }
    {
    }

protected:
    FakeAdcState state;
    AdcSpec spec;
    Adc adc;
};


TEST_F(AdcTestFixture, AdcInitializationSetsChannelAndSequence)
{
    adc.initialize();
    EXPECT_TRUE(state.channelSet);
    EXPECT_TRUE(state.sequenceInitialized);
}

TEST_F(AdcTestFixture, AdcStoresReadedMessage)
{
    adc.read();
    EXPECT_TRUE(state.readCalled);
    EXPECT_EQ(adc.lastReading(), state.readValue);
}
