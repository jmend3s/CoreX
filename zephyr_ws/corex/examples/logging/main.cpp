
#include "Printer.h"
#include "LoggerWorker.h"
#include "LoggerMacros.h"

#include "Delay.h"


#define CK_LOG_MODULE "MAIN"

int main()
{
    Printer printer;
    LoggerWorker loggerWorker(printer);

    int32_t i = 42;
    int32_t ii = -42;
    float f = 4.2f;
    float ff = -4.2f;


    while (true)
    {
        CK_LOG_INFO("Hello World", i, ii, f, ff);
        loggerWorker.work();

        Delay::ms(500);
    }
}
