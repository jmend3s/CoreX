
#ifndef __BOARD_CONFIGURATION_H__
#define __BOARD_CONFIGURATION_H__

#include "platform/Gpio.h"


struct BoardHardware
{
    GpioSpec led;
};

class BoardConfiguration
{
public:
    BoardConfiguration();

    BoardHardware const& board() const;

private:
    static BoardHardware create();

    BoardHardware _board;
};


#endif
