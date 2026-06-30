
#include "platform/Gpio.h"

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>


static constexpr gpio_dt_spec ledDt = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static GpioSpec ledSpec(reinterpret_cast<uintptr_t>(&ledDt));

int main()
{
    Gpio led(ledSpec, GpioMode::Output); // <- ONLY here

    while (true) {
        led.set(GpioState::High);
        k_sleep(K_SECONDS(1));
        led.set(GpioState::Low);
        k_sleep(K_SECONDS(1));
    }
}
