
#ifndef __TEST_COMPONENT_H__
#define __TEST_COMPONENT_H__

#include "Component.h"


class TestComponent : public Component
{
public:
    void initialize() override;
    void update() override;
    uint32_t period() const override;

    uint32_t currentTick() const;
    bool initialized() const;

    void setUpdatePeriod(uint32_t period);

private:
    bool _init = false;
    uint32_t _period = 0;
    uint32_t _currentUpdateTurn = 0;
};

#endif