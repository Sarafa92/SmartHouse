#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 
#include "dimmerquattro.h"


void dimmerquattropiu(uint8_t val){
	printf("sono in bo1\n");
	while(OCR2A!=(val+51)){
		printf("sono in bo  val: %d\n",OCR2A);
		_delay_ms(10);
		OCR2A+=1;
	}
}

void dimmerquattromeno(uint8_t val){
	printf("sono in bo1\n");
	while(OCR2A!=(val-51)){
		printf("sono in bo  val: %d\n",OCR2A);
		_delay_ms(10);
		OCR2A-=1;
	}
}
