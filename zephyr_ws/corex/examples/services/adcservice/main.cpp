
#include "Adc.h"
#include "AdcService.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>


static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));

int main()
{
    Adc adc(adcChannel);
    AdcService::AdcEntry adcEntries[] = { { &adc, AdcService::Rate::Ms100 } };

    TimerService const timerService;
    AdcService adcService(adcEntries, 1, timerService);

    adcService.initialize();

    while (1)
    {
        adcService.update();
        int32_t const value = adc.lastReading();
        printk("value = %ld\n", value);
    }
}
