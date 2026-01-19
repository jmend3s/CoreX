
#ifndef __BLINK_SERVICE_H__
#define __BLINK_SERVICE_H__

#include "SchedulableComponent.h"
#include "Gpio.h"
#include "TimerService.h"


class BlinkService : public SchedulableComponent
{
public:
    BlinkService(Gpio& pin, TimerService& timer);

    void initialize() override;
    void update() override;
    uint32_t periodTick() const override;

private:
    Gpio& _pin;
    TimerService& _timer;
};


#endif
