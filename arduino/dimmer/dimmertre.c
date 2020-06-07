#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmertre.h"

void dimmertrepiu(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1AL!=(val+51)){
		printf("sono in bo  val: %d\n",OCR1AL);
		_delay_ms(10);
		OCR1AL+=1;
	}
}

void dimmertremeno(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1AL!=(val-51)){
		printf("sono in bo  val: %d\n",OCR1AL);
		_delay_ms(10);
		OCR1AL-=1;
	}
}
