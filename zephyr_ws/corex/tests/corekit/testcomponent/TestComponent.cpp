
#include "TestComponent.h"

void TestComponent::initialize()
{
    _init = true;
}

void TestComponent::update()
{
    _currentUpdateTurn += 1;
}

uint32_t TestComponent::periodTick() const
{
    return _period;
}

uint32_t TestComponent::currentTick() const
{
    return _currentUpdateTurn;
}

bool TestComponent::initialized() const
{
    return _init;
}

void TestComponent::setUpdatePeriod(uint32_t const period)
{
    _period = period;
}
