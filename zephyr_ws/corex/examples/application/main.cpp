
#include "services/BlinkService.h"

#include "System.h"
#include "TimerService.h"
#include "Gpio.h"

#include <zephyr/kernel.h>

#include "SystemTime.h"

#define LED_NODE DT_ALIAS(led0)

static constexpr gpio_dt_spec ledSpec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

class Application
{
public:
    Application()
        : _led(ledSpec, Gpio::Mode::Output)
        , _blink(_led, _timer)
    {
        _components[0] = &_timer;
        _components[1] = &_blink;
    }

    SchedulableComponent** components()
    {
        return _components;
    }

    uint64_t* storage()
    {
        return _tickStorage;
    }

    size_t count()
    {
        return 2;
    }

    SystemTime& time()
    {
        return _time;
    }

private:
    Gpio _led;

    TimerService _timer;
    BlinkService _blink;

    uint64_t _tickStorage[2];
    SchedulableComponent* _components[2];

    SystemTime _time;
};

int main()
{
    Application app;
    System system(app.components(), app.storage(), app.count(), app.time());

    system.run();
}
