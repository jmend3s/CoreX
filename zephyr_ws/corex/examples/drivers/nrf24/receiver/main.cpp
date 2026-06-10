#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// 'led0' is typically mapped to the red component of the onboard RGB LED
#define LED_NODE DT_ALIAS(led0)

// Verify at compile time that the devicetree actually has this alias configured
static_assert(DT_NODE_HAS_STATUS_OKAY(LED_NODE), "Unsupported board: led0 alias is not defined");

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    // Ensure the driver is ready
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    // Configure the pin. GPIO_OUTPUT_ACTIVE honors the active-low flag in the DT.
    int ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    while (true) {
        gpio_pin_toggle_dt(&led);
        k_msleep(500); // Toggle every 500ms
    }
}