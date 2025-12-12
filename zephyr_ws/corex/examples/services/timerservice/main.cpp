
#include "Gpio.h"
#include "TimerService.h"

#include <zephyr/kernel.h>


#define LED_NODE DT_ALIAS(gpioled0)

static constexpr gpio_dt_spec ledSpec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main()
{
    Gpio led(ledSpec, Gpio::Mode::Output);
    led.initialize();

    TimerService timerService;
    timerService.initialize();

    while (true)
    {
        timerService.update();
        if (timerService.ms100())
        {
            led.toggle();
        }
    }
}
