#include <stdio.h>
#include <system.h>
#include <sys/alt_timestamp.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/alt_alarm.h>
#include <alt_types.h>

volatile int *AK = (int*)AK_BASE;
volatile int *data = (int*)LCD_DATA_BASE;
volatile int *RW = (int*)RW_BASE;
volatile int *RS = (int*)RS_BASE;
volatile int *EN = (int*)EN_BASE;
volatile int *sw = (int*)SWITCHES_BASE;
volatile int *led = (int*)LEDR_BASE;
int i = 1;

int main()
{
	*EN = 0;
	*RW = 0x00;
	*RS = 0x00;
	*data = 0x30;
	usleep(1000);
	*EN = 1;
	usleep(1000);
	*EN = 0;

	*data = 0x0E;
		usleep(1000);
		*EN = 1;
		usleep(1000);
		*EN = 0;

	*data = 0x06;
	usleep(1000);
	*EN = 1;
	usleep(1000);
	EN = 0;

	*RS = 1;
	*RW = 0;
	*data = 0x48;
	usleep(1000);
	*EN = 1;
	usleep(1000);
	EN = 0;


  printf("Hello from Nios II!\n");

  while (1){
	  *led = *sw;
  }

  return 0;
}
