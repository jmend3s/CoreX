
#include "Application.h"


Application::Application(BoardHardware board)
    : _led(board.led, GpioMode::Output)
    , _blink(_led, _timer)
{
    _components[0] = &_timer;
    _components[1] = &_blink;
}

Component** Application::components()
{
    return _components;
}

uint64_t* Application::storage()
{
    return _tickStorage;
}

size_t Application::count()
{
    return 2;
}

TimeSource& Application::time()
{
    return _time;
}