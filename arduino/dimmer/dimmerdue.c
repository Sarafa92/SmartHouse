#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmerdue.h"

void dimmerduepiu(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1BL!=(val+51)){
		printf("sono in bo  val: %d\n",OCR1BL);
		_delay_ms(10);
		OCR1BL+=1;
	}
}

void dimmerduemeno(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1BL!=(val-51)){
		printf("sono in bo  val: %d\n",OCR1BL);
		_delay_ms(10);
		OCR1BL-=1;
	}
}
