
#include "BoardConfiguration.h"

#include <zephyr/drivers/gpio.h>


static constexpr gpio_dt_spec ledDt = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

BoardConfiguration::BoardConfiguration()
    : _board(create())
{
}

BoardHardware const& BoardConfiguration::board() const
{
    return _board;
}

BoardHardware BoardConfiguration::create()
{
    return BoardHardware
    {
        GpioSpec(reinterpret_cast<uintptr_t>(&ledDt))
    };
}
