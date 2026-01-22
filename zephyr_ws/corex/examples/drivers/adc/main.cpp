
#include "Adc.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>


static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

int main()
{
    Adc adc(adcSpec);

    adc.initialize();

    while (true)
    {
        adc.read();
        auto lastRead = adc.lastReading();
        k_sleep(K_MSEC(1000));
    }
}
