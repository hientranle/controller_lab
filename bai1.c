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
	 int i = 0;
	 *led = i;
	 i++;
	 if (i == 1024){
		 i = 0;
	 }
	 return alt_ticks_per_second()/2;
 }
 int main (){
	 static alt_alarm alarm;
	 if (alt_alarm_start(&alarm, alt_ticks_per_second(), my_alarm_callback, NULL)<0){
		 printf("No system clock available!\n");
	 }
	 while (1){

	 }
	 return 0;
 }

