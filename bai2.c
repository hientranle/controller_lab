/*
 * bai2.c
 *
 *  Created on: Nov 1, 2020
 *      Author: PC
 */

#include <stdio.h>
#include <system.h>
#include <sys/alt_timestamp.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/alt_alarm.h>
#include <alt_types.h>
 static int led_state = 31;
 volatile int *led = (int*)LEDR_BASE;
 volatile int *sw = (int*)SWITCHES_BASE;
 alt_u32 my_alarm_callback(void* context){
	 if (sw == 2){
	 int i = 0;
	 i = i | ((led_state&1)<<1) | ((led_state&2)<<2) | ((led_state&4)<<3) | ((led_state&8)<<4) | ((led_state&16)<<5);
	 *led = i;
	 led_state--;
	 if (led_state == -1){
		 led_state = 31;
	 	 }
	 else {
		 *led = 0x00;
	 	 }
	 }
	 return alt_ticks_per_second()/4;
 }


