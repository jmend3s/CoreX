
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/printk.h>


static const i2c_dt_spec mpu = I2C_DT_SPEC_GET(DT_ALIAS(mpu6050test));

int main()
{
    if (!i2c_is_ready_dt(&mpu))
    {
        printk("I2C is not ready\n");
        return 0;
    }

    uint8_t reg = 0x75;
    uint8_t value = 0;

    while (true)
    {
        int ret = i2c_write_read_dt(&mpu, &reg, 1, &value, 1);

        if (ret == 0)
        {
            printk("WHO_AM_I: 0x%X\n", value);
        }
        else
        {
            printk("I2C read failed (%d)\n", ret);
        }
        k_sleep(K_MSEC(100));
    }
}
