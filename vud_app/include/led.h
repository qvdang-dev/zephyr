#include <stdio.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

/* 1000 msec = 1 sec */

/* The devicetree node identifier for the "led0" alias. */

bool led_init(void);
bool led_toggle(uint32_t delay_ms);