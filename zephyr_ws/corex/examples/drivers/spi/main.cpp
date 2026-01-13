
#include "Spi.h"

#include <zephyr/sys/printk.h>


#define SPI_OP (SPI_OP_MODE_MASTER | SPI_WORD_SET(8) | SPI_LINES_SINGLE)
static constexpr spi_dt_spec spiSpec = SPI_DT_SPEC_GET(DT_ALIAS(spitest), SPI_OP, 0);

int main()
{
    Spi const spi(spiSpec);

    uint8_t tx = 0xAA;
    uint8_t rx = 0x00;

    while (true)
    {
        rx = 0x00;
        if (spi.transceive(&tx, &rx, 1))
        {
            printk("TX=0x%02X RX=0x%02X\n", tx, rx);
        }
        k_sleep(K_MSEC(1000));
    }
}
