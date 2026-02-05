#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include "led.h"

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

static const struct gpio_dt_spec led_o = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led_g = GPIO_DT_SPEC_GET(LED1_NODE, gpios);

bool led_init(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led_o)) {
		return false;
	}

	if (!gpio_is_ready_dt(&led_g)) {
		return false;
	}

	ret = gpio_pin_configure_dt(&led_o, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return false;
	}

	ret = gpio_pin_configure_dt(&led_g, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return false;
	}

	return true;
}

bool led_toggle(uint32_t delay_ms)
{
	int ret;
	ret = gpio_pin_toggle_dt(&led_o);
	if (ret < 0) {
		return false;
	}
	ret = gpio_pin_toggle_dt(&led_g);
	if (ret < 0) {
		return false;
	}

	k_msleep(delay_ms);
	return true;
}
