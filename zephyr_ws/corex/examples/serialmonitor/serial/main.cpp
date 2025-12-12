
#include <zephyr/kernel.h>


int main()
{
    while (1)
    {
        printk("Tick...\n");
        k_sleep(K_SECONDS(1));
    }
}
