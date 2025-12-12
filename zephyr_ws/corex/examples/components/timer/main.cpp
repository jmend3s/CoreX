
#include "Gpio.h"
#include "Timer.h"

#include <zephyr/kernel.h>


#define LED_NODE DT_ALIAS(gpioled0)

static constexpr gpio_dt_spec ledSpec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main()
{
    Gpio led(ledSpec, Gpio::Mode::Output);
    led.initialize();

    Timer timer(500);
    timer.initialize();

    while (true)
    {
        timer.update();
        if (timer.elapsed())
        {
            led.toggle();
        }
    }
}
