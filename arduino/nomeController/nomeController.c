#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include "uart.h"



char* set_nome_controller(void){
	printf_init();

//inizializzo UART per comunicare
 // UART_init();
  //Trasmetto stringa di benvenuto, per assegnazione nome
  UART_putString((uint8_t*)"Benvenuto, assegnami un nome.\n");
  //mi alloco un buffere di 16 caratteri che mi permette di scambiare messaggi con arduino
  uint8_t buf[16];
  
  while(1) {
    uint8_t num_bit = UART_getString(buf);
    //verifico se il numero di caratteri assegnati è maggiore della dimensione del buffer
    if(num_bit>16){
     UART_putString((uint8_t*)"Attenzione! Il nome deve essere al massimo di 16 lettere\n"); //richiedo di assegnare il nome
     UART_putString((uint8_t*)"Assegnami un nome\n");
     UART_getString(buf); //prendo il nome inserito in input
    }
    
    UART_putString((uint8_t*)"Bene, ora mi chiamo "); 
   
    //salvo il nome in un array 
    char nome[16];
    int i =0;
    for(i=0;i<16;i++){
    	nome[i]=buf[i];
    }
    
    
    
    //trasmetto il nome
    UART_putString((uint8_t*)nome);
    
    
     
     printf("Sto stampando il nome\n");
     printf(nome);
     
     char* nomeret = malloc(sizeof(char*)*16);
     nomeret = nome;
     
     return nomeret;
  }
}





int main(void){

	UART_init();

	//set name controller
void set_name(void){
	
		//char* nome = malloc(sizeof(char*)*16);
		char* nome= set_nome_controller();
		char n[16];
		for(int i=0;i<16;i++){
		n[i]=*nome+i;
		}
		printf("Sto nel main\n");
		printf(n);


}	
	set_name();

	
	



}
