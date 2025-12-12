
#include "Pwm.h"

#include <zephyr/kernel.h>


#define PWM_LED_NODE DT_ALIAS(pwm_led0)

static constexpr pwm_dt_spec pwmLedSpec = PWM_DT_SPEC_GET(PWM_LED_NODE);

int main()
{
    Pwm pwmLed(pwmLedSpec);

    pwmLed.initialize();
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
