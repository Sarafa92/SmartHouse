#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

//#include "accendiLed.h"

int main(void){
	 // UART_init();
	 // uint8_t buf[16];
	 //il pin 13 è il bit 7, pin 12 bit 6, pin 11 bit 5, pin 10 bit 4
	  uint8_t mask1 = (1<<7);
	  uint8_t mask2 = (1<<6);
	  uint8_t mask3 = (1<<5);
	  uint8_t mask4 = (1<<4);
	 
	 //setto i pin 13,12,11,10 come output
	 DDRB |= mask1;
	 DDRB |= mask2;
	 DDRB |= mask3;
	 DDRB |= mask4;

while(1){
     /*   UART_putString((uint8_t*)"Scegli luce da accendere\n");
				 UART_getString(buf); //prendo il nome inserito in input
			 int i=0;
				 char led[8];
				 for(i=0;i<8;i++){
					led[i]=buf[i];
				}

	*/
		/* accendo i led */
		if(strncmp(led,"uno",strlen("uno"))==0){
			if(!(PORTB&mask1)){
				PORTB |= mask1;
				_delay_ms(100);
			}else{
				PORTB &= ~mask1;
				_delay_ms(100);
			}
		}
				if(strncmp(led,"due",strlen("due"))==0){
				if(!(PORTB&mask2)){
				PORTB |= mask2;
				_delay_ms(100);
			}else{
				PORTB &= ~mask2;
				_delay_ms(100);
			}
		}
		
			if(strncmp(led,"tre",strlen("tre"))==0){
				if(!(PORTB&mask3)){
				PORTB |= mask3;
				_delay_ms(100);
			}else{
				PORTB &= ~mask3;
				_delay_ms(100);
			}
		}
		
			if(strncmp(led,"quattro",strlen("quattro"))==0){
				if(!(PORTB&mask4)){
				PORTB |= mask4;
				_delay_ms(100);
			}else{
				PORTB &= ~mask4;
				_delay_ms(100);
			}
		}
		
}

}
