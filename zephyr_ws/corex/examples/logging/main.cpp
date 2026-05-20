
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


    while (true)
    {
        CK_LOG_INFO("Hello World", i, 420);
        loggerWorker.work();

        Delay::ms(500);
    }
}
