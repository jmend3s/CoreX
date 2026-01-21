
#include "Adc.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>

#define LED_NODE DT_ALIAS(adc0)

static constexpr adc_dt_spec adcLedSpec = ADC_DT_SPEC_GET(DT_ALIAS(adc0));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcLedSpec));

int main()
{
    // Gpio led(ledSpec, Gpio::Mode::Output);
    // led.initialize();
    //
    // while (true)
    // {
    //     led.set(Gpio::State::High);
    //     k_sleep(K_SECONDS(1));
    //     led.set(Gpio::State::Low);
    //     k_sleep(K_SECONDS(1));
    // }
}
