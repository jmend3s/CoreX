
#include "Delay.h"
#include "Logger.h"


int main()
{
    while (true)
    {
        CK_LOG_INFO("Hello World");
        Delay::ms(500);
    }
}
