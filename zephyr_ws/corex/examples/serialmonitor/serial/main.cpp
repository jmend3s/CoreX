
#include "TimerMs.h"
#include "PrinterK.h"


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
            PrinterK::print("Tick... count: %i\n", tickCount++);
        }
    }
}
