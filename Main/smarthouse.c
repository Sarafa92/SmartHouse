#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>

#include "smarthouse.h"
#include "../arduino/dimmer/pwm_init.h"

#include "../avr_common/uart.h" 






int main(void){
	
	printf_init();
  //imposto i registri a 0
 
  /*OCR1AL=0;
  OCR1BL=0;
  OCR2A=0;
  OCR1CL=0;*/
  
  

	//NOME CONTROLLER
	
	//inizializzo UART per comunicare
  UART_init();
  
  pwm_init();
  
   
  uint8_t buf[16];
  uint8_t num_bit ;
  //Trasmetto stringa di benvenuto, per assegnazione nome
  UART_putString((uint8_t*)"Benvenuto, assegnami un nome.\n");
  //mi alloco un buffere di 16 caratteri che mi permette di scambiare messaggi con arduino
 
 
   num_bit = UART_getString(buf);
   //verifico se il numero di caratteri assegnati è maggiore della dimensione del buffer
   if(num_bit>16){
     UART_putString((uint8_t*)"Attenzione! Il nome deve essere al massimo di 8 lettere\n"); //richiedo di assegnare il nome
     UART_putString((uint8_t*)"Assegnami un nome\n");
     UART_getString(buf); //prendo il nome inserito in input
    }
    
    UART_putString((uint8_t*)"Bene, mi chiamo "); 
    //salvo il nome in un array 
    char nome[16];
    int i =0;
    for(i=0;i<16;i++){
    	nome[i]=buf[i];
    }
    //trasmetto il nome
    UART_putString((uint8_t*)nome);
    
    id_pin id[3];
    
    for(int i=0; i<3; i++){
    
    	id[i].indexArray = i;
    	id[i].nomeController = nome;
   
    }
    
   while(1){
    
    
     UART_putString((uint8_t*)"Scegli una operazione\n 1. switch\n 2. dimmer+\n 3. dimmer-\n 4. on/off");
     UART_getString(buf); //prendo il nome inserito in input
   
     char operat[8];
     for(i=0;i<8;i++){
    	operat[i]=buf[i];
    }
    
    char* valore = operat;
    printf("iL valore di operat ");
    			printf((uint8_t*)operat);
    			
    UART_putString((uint8_t*)operat);
     if(strncmp(valore,"1",strlen("1"))==0){
 				printf("1 iL valore di operat ");
    			printf((uint8_t*)operat);
  
				 UART_putString((uint8_t*)"Scegli uno switch\n");
				 UART_getString(buf); //prendo il nome inserito in input
			 
				 char switchid[16];
				 for(i=0;i<16;i++){
					switchid[i]=buf[i];
				}
				
 
					
					UART_putString((uint8_t*)"Assegno nome allo switch ");
					UART_putString((uint8_t*)switchid);
					UART_getString(buf); //prendo il nome inserito in input
					
					 char nomedevice[16];
					 for(i=0;i<16;i++){
						nomedevice[i]=buf[i];
					}
			 
			 
				
					UART_putString((uint8_t*)"nome device ");
					UART_putString((uint8_t*)nomedevice);
					
					if(strncmp(switchid,"uno",strlen("uno"))==0){
						id[0].nomeSwitch = nomedevice;
					}
					if(strncmp(switchid,"due",strlen("due"))==0){
						id[1].nomeSwitch = nomedevice;
					}
					if(strncmp(switchid,"tre",strlen("tre"))==0){
						id[2].nomeSwitch = nomedevice;
					}
					if(strncmp(switchid,"quattro",strlen("quattro"))==0){
						id[3].nomeSwitch = nomedevice;
					}
    }
    else if(strncmp(valore,"2",strlen("2"))==0){ //dimmer+
    			
    			printf("2 iL valore di operat  ");
    			printf((uint8_t*)operat);
    			
    			
					UART_putString((uint8_t*)"Scegli switch da dimmerare");
					UART_getString(buf); //prendo il nome inserito in input
					
					 char s[8];
					 for(i=0;i<8;i++){
						s[i]=buf[i];
					}
				
						
						dimmerpiu(s);
			
    	
    }else if(strncmp(operat,"3",strlen("3"))==0){ //dimmer-
    	 
    		
					UART_putString((uint8_t*)"Scegli switch da dimmerare");
					UART_getString(buf); //prendo il nome inserito in input
					
					 char s[8];
					 for(i=0;i<8;i++){
						s[i]=buf[i];
					}
					
			
						dimmermeno(s);
			

    }else if(strncmp(operat,"4",strlen("4"))==0){
    			UART_putString((uint8_t*)"Scegli switch da accendere/spegnere");
					UART_getString(buf); //prendo il nome inserito in input
					
					 char s[8];
					 for(i=0;i<8;i++){
						s[i]=buf[i];
					}
					
					
						led_on_off(s);
				
   }
 }
 
 }
    
    



