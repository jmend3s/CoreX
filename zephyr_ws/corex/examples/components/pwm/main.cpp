
#include <>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/device.h>

LOG_MODULE_REGISTER(pwm_example, LOG_LEVEL_INF);

#define PWM_LED_NODE DT_ALIAS(pwm_led0)

#if !DT_NODE_HAS_STATUS(PWM_LED_NODE, okay)
#error "pwm_led0 alias is not defined or not okay in devicetree"
#endif

static const struct pwm_dt_spec pwmLedSpec = PWM_DT_SPEC_GET(PWM_LED_NODE);

int main()
{
    Pwm pwmLed(pwmLedSpec);

    if (pwmLed.initialize())
    {
        uint32_t const period = pwmLed.periodNs();
        uint32_t const step = period / 100U;

        while (true)
        {
            for (uint32_t pulse = 0; pulse <= period; pulse += step)
            {
                pwmLed.setPulseNs(pulse);
                k_msleep(20);
            }

            for (uint32_t pulse = period; pulse > 0; pulse -= step)
            {
                pwmLed.setPulseNs(pulse);
                k_msleep(20);
            }
        }
    }

}
