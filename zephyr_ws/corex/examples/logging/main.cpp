
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
    uint32_t ui = 42;
    float f = 4.2f;
    float ff = -4.2f;
    auto* ptr = reinterpret_cast<void*>(0x20001000);
    uint32_t hex = 0xDEADBEEF;
    uint32_t binary = 0b10110110;


    struct Binary32
    {
        uint32_t value;
    };

    struct Hexadecimal
    {
        uint32_t value;
    };

    while (true)
    {
        CK_LOG_INFO("String: ", "Hello World!");
        CK_LOG_INFO("int32: ", i, ii);
        CK_LOG_INFO("uint32: ", ui);
        CK_LOG_INFO("Float: ", f, ff);
        CK_LOG_INFO("Pointer: ", ptr);
        CK_LOG_INFO("Hexadecimal: ", Hexadecimal { hex });
        CK_LOG_INFO("Binary: ", Binary32 { binary });
        loggerWorker.work();

        Delay::ms(500);
    }
}
