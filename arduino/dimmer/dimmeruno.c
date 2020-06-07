#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "dimmeruno.h"


void dimmerunopiu(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1CL!=(val+51)){
		printf("sono in bo  val: %d\n",OCR1CL);
		_delay_ms(10);
		OCR1CL+=1;
	}
}

void dimmerunomeno(uint8_t val){
	printf("sono in bo1\n");
	while(OCR1CL!=(val-51)){
		printf("sono in bo  val: %d\n",OCR1CL);
		_delay_ms(10);
		OCR1CL-=1;
	}
}
