
#include "SystemPrint.h"
#include "TimerMs.h"

#include <zephyr/kernel.h>


int main()
{
    TimerMs timer(500);
    timer.initialize();

    int tickCount = 0;
    while (1)
    {
        timer.update();
        if (timer.elapsed())
        {
            SystemPrint::print("Tick... count: %i\n", tickCount++);
        }
    }
}
