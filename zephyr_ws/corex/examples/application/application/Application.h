
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../hardware/BoardConfiguration.h"
#include "../services/BlinkService.h"

#include "System.h"
#include "TimeSource.h"
#include "TimerService.h"
#include "platform/Gpio.h"


class Application
{
public:
    Application(BoardHardware board);

    Component** components();
    uint64_t* storage();
    size_t count();
    TimeSource& time();

private:
    Gpio _led;

    TimerService _timer;
    BlinkService _blink;

    uint64_t _tickStorage[2];
    Component* _components[2];

    TimeSource _time;
};

#endif
