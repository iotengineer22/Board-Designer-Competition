/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */

 #include <zephyr/kernel.h>
 #include <zephyr/sys/printk.h>
 #include <zephyr/device.h>
 #include <zephyr/drivers/pwm.h>
 
 static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));
 
 #define PWM_PERIOD PWM_USEC(20000U)   // 20ms PWM Period
 #define MIN_PULSE PWM_USEC(600U)  // 0.6ms
 #define MAX_PULSE PWM_USEC(2400U) // 2.4ms
 
 int main(void) {
   uint32_t pulse_width;
   uint8_t dir = 0U;
   int ret;
 
   printk("PWM-based servo control\n");
 
   if (!pwm_is_ready_dt(&pwm_led0)) {
	 printk("Error: PWM device %s is not ready\n", pwm_led0.dev->name);
	 return 0;
   }
 
   pulse_width = MIN_PULSE; // Start at the minimum pulse width
 
   while (1) {
	 ret = pwm_set_dt(&pwm_led0, PWM_PERIOD, pulse_width); // Set the pulse width
	 if (ret) {
	   printk("Error %d: failed to set pulse width\n", ret);
	   return 0;
	 }
	 printk("Pulse width: %d us\n", (int)pulse_width / 1000); // microsecond
	 k_sleep(K_SECONDS(1U));
 
	 if (dir == 0) { // Increasing pulse width
	   pulse_width += PWM_USEC(200); // Increment by 10us(you can adjust it).
	   if (pulse_width > MAX_PULSE) {
		 pulse_width = MAX_PULSE; // Limit the pulse width
		 dir = 1;           // Change direction to decreasing
	   }
	 } else { // Decreasing pulse width
	   pulse_width -= PWM_USEC(200); // Decrement by 10us(you can adjust it).
	   if (pulse_width < MIN_PULSE) {
		 pulse_width = MIN_PULSE; // Limit the pulse width
		 dir = 0;           // Change direction to increasing
	   }
	 }
   }
   return 0;
 }
