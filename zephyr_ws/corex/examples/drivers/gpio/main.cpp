
#include "Gpio.h"

#include <zephyr/kernel.h>


#define LED_NODE DT_ALIAS(gpioled0)

static constexpr gpio_dt_spec ledSpec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main()
{
    Gpio led(ledSpec, Gpio::Mode::Output);
    led.initialize();

    while (true)
    {
        led.set(Gpio::State::High);
        k_sleep(K_SECONDS(1));
        led.set(Gpio::State::Low);
        k_sleep(K_SECONDS(1));
    }
}
