
#include "Adc.h"
#include "SystemPrint.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>


static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

int main()
{
    SystemPrint::print("Initializing...\n");
    k_sleep(K_MSEC(500));
    Adc adc(adcSpec);

    adc.initialize();

    while (true)
    {
        adc.read();
        auto const lastRead = adc.lastReading();
        SystemPrint::print("read: %i\n", lastRead);
        k_sleep(K_MSEC(1000));
    }
}
