
#include "Spi.h"
#include "FakeHalSpi.h"

#include <gtest/gtest.h>


class SpiTestsFixture : public ::testing::Test
{
public:
    SpiTestsFixture()
        : spec { reinterpret_cast<uintptr_t>(&state) }
        , spi { spec }
    {
    }

protected:
    FakeSpiState state;
    SpiSpec spec;
    Spi spi;
};


TEST_F(SpiTestsFixture, SpiReads)
{
    uint8_t rx;

    spi.read(&rx, 1);
    EXPECT_EQ(rx, state.rx);
    EXPECT_EQ(state.lastSize, 1);
    EXPECT_EQ(state.transceiveCalls, 1);
}

TEST_F(SpiTestsFixture, SpiWrites)
{
    uint8_t tx = 0x42;
    size_t size = 1;

    spi.write(&tx, size);
    EXPECT_EQ(state.lastTx, tx);
    EXPECT_EQ(state.lastSize, size);
    EXPECT_EQ(state.transceiveCalls, 1);

    tx = 0xAA;
    size = 5;

    spi.write(&tx, size);
    EXPECT_EQ(state.lastTx, tx);
    EXPECT_EQ(state.lastSize, size);
    EXPECT_EQ(state.transceiveCalls, 2);
}

TEST_F(SpiTestsFixture, SpiTransceives)
{
    uint8_t rx;
    uint8_t tx = 0x24;
    size_t size = 3;

    spi.transceive(&tx, &rx, size);
    EXPECT_EQ(state.lastSize, size);

    EXPECT_EQ(rx, state.rx);
    EXPECT_EQ(state.transceiveCalls, 1);

    EXPECT_EQ(state.lastTx, tx);
    EXPECT_EQ(state.transceiveCalls, 1);
}
