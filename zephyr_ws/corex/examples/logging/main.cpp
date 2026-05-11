
#include "Delay.h"

#include "LoggerWorker.h"
#include "LoggerMacros.h"
#include "Printer.h"


#define CK_LOGGER_MODULE "MAIN"

int main()
{
    Printer printer;
    LoggerWorker loggerWorker(printer);


    CK_LOG_INFO("SYSTEM START");
    loggerWorker.work();
    while (true)
    {
        // CK_LOG_INFO("Hello World");

        // loggerWorker.work();

        // Delay::ms(500);
    }
}
