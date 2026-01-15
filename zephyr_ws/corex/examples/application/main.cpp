
#include "services/BlinkService.h"

#include "System.h"
#include "TimerService.h"
#include "Gpio.h"

#include <zephyr/kernel.h>

#include <cstdint>


#define LED_NODE DT_ALIAS(led0)

static constexpr gpio_dt_spec ledSpec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

class Application
{
public:
    Application()
        : _led(ledSpec, Gpio::Mode::Output)
        , _blink(_led, _timer)
        , _components { &_timer, &_blink }
        , _system(_components, _tickStorage, 2)
    {}

    void loop()
    {
        _system.run();
    }

private:
    Gpio _led;

    TimerService _timer;
    BlinkService _blink;

    uint64_t _tickStorage[2];
    SchedulableComponent* _components[2];
    System _system;
};

int main()
{
    Application app;
    app.loop();
}
