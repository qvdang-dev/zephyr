/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "led.h"

int main(void)
{
	if (led_init() != true) {
		printf("Error: LED initialization failed\n");
		return 0;
	}

	while (1) {
		if (led_toggle(1000) != true) {
			printf("Error: LED toggle failed\n");
			return 0;
		}
	}
	return 0;
}
