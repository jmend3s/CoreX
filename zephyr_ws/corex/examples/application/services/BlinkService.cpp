
#include "BlinkService.h"


BlinkService::BlinkService(Gpio& pin, TimerService& timer)
    : _pin(pin)
    , _timer(timer)
{
}

void BlinkService::initialize()
{
    _pin.configure();
}

void BlinkService::update()
{
    if (_timer.ms1000())
    {
        _pin.toggle();
    }
}

uint32_t BlinkService::period() const
{
    return 1;
}
