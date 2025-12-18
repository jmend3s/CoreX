
#include "TimerService.h"

#include <zephyr/kernel.h>


int main()
{
    TimerService timerService;
    timerService.initialize();

    while (true)
    {
        timerService.update();
        if (timerService.ms100())
        {
            printk("Tick...");
        }
    }
}
