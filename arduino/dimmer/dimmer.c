#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include "../avr_common/uart.h" 

#include "pwm_init.h"

 
 
 
 while(1){
 
 		
 
 
 
 }
 
 
 
 }

/*int main(void){
  	printf_init(); 
		//INIZIALIZZO TIMER E PORTE
 		pwm_init();
  
    UART_init();
 		
 		
		uint8_t buf[16];
 		 UART_putString((uint8_t*)"Scegli switch?\n");
   	 UART_getString(buf);
 		
 		char nome[8];
   	int i =0;
    	for(i=0;i<8;i++){
    	   nome[i]=buf[i];
    	}
    	
    	UART_putString((uint8_t*) "Bene ora mi chiamo :");
    	UART_putString((uint8_t*)nome);
	
  while(1){
  

   
   
  
 if(strncmp(nome,"uno",strlen("uno"))==0){
  	//led 13
  	printf("Caso1\n");
  	   UART_putString((uint8_t*)"Luminosita?\n");
   	   UART_getString(buf);
  
  	char lum[8];
   	int i =0;
    	for(i=0;i<8;i++){
    	   lum[i]=buf[i];
    	}
    	
    	
  	if(strncmp(lum,"100%",strlen("100%"))==0){
  	while(OCR1CL<248){
  		 _delay_ms(100); 
  		OCR1CL+=10;
  		
  	}
  	}else if(strncmp(lum,"50%",strlen("50%"))==0){
  	if(OCR1CL>170){
  		while(OCR1CL>170){
  		 	_delay_ms(100); 
  			OCR1CL-=10;
  		
  		}
  	}else if(OCR1CL<170){
  		while(OCR1CL<170){
  			_delay_ms(100);
  			OCR1CL+=10;
  		}
  	}
  	}else if(strncmp(lum,"30%",strlen("30%"))==0){
  		if(OCR1CL>85){
  		while(OCR1CL>85){
  		 	_delay_ms(100); 
  			OCR1CL-=10;
  		
  		}
  	}else if(OCR1CL<85){
  		while(OCR1CL<85){
  			_delay_ms(100);
  			OCR1CL+=10;
  		}
  	}
  		
  	}else{
  		OCR1CL=0;
  	}

  }else if(strncmp(nome,"due",strlen("due"))==0){
  	//led 12
  	printf("Caso2\n");
  	   UART_putString((uint8_t*)"Luminosita?\n");
   	   UART_getString(buf);
  
  	   char lum[8];
   	   int i =0;
    	   for(i=0;i<8;i++){
    	   lum[i]=buf[i];
    	}
    	
  	 if(strncmp(lum,"100%",strlen("100%"))==0){
  	
  		while(OCR1AL<248){
  			_delay_ms(100);
  			OCR1AL+=10;
  		}
  	}else if(strncmp(lum,"50%",strlen("50%"))==0){
  			if(OCR1AL>170){
  		while(OCR1AL>170){
  		 	_delay_ms(100); 
  			OCR1AL-=10;
  		
  		}
  	}else if(OCR1AL<170){
  		while(OCR1AL<170){
  			_delay_ms(100);
  			OCR1AL+=10;
  		}
  	}
  	}else if(strncmp(lum,"30%",strlen("30%"))==0){
  			if(OCR1AL>85){
  		while(OCR1AL>85){
  		 	_delay_ms(100); 
  			OCR1AL-=10;
  		
  		}
  	}else if(OCR1AL<85){
  		while(OCR1AL<85){
  			_delay_ms(100);
  			OCR1AL+=10;
  		}
  	}
  	}else{
  		OCR1AL=0;
  	}
  
  }else if(strncmp(nome,"tre",strlen("tre"))==0){
  	//led 11
  	printf("Caso3\n");
  	  UART_putString((uint8_t*)"Luminosita?\n");
   	   UART_getString(buf);
  
  	   char lum[8];
   	   int i =0;
    	   for(i=0;i<8;i++){
    	   lum[i]=buf[i];
    	}
  	if(strncmp(lum,"100%",strlen("100%"))==0){
  		while(OCR1BL<248){
  			_delay_ms(100);
  			OCR1BL+=10;
  		}
  	}else if(strncmp(lum,"50%",strlen("50%"))==0){
  			if(OCR1BL>170){
  		while(OCR1BL>170){
  		 	_delay_ms(100); 
  			OCR1BL-=10;
  		
  		}
  	}else if(OCR1BL<170){
  		while(OCR1BL<170){
  			_delay_ms(100);
  			OCR1BL+=10;
  		}
  	}
  	}else if(strncmp(lum,"30%",strlen("30%"))==0){
  		if(OCR1BL>85){
  		while(OCR1BL>85){
  		 	_delay_ms(100); 
  			OCR1BL-=10;
  		
  		}
  	}else if(OCR1BL<85){
  		while(OCR1BL<85){
  			_delay_ms(100);
  			OCR1BL+=10;
  		}
  	}
  	}else{
  		OCR1BL=0;
  	}
  	
  
  }else if(strncmp(nome,"quattro",strlen("quattro"))==0){
  	//led 10
  	printf("Caso4\n");
  	
  	  UART_putString((uint8_t*)"Luminosita?\n");
   	   UART_getString(buf);
  
  	   char lum[8];
   	   int i =0;
    	   for(i=0;i<8;i++){
    	   lum[i]=buf[i];
    	}
    	
    	
  	 	if(strncmp(lum,"100%",strlen("100%"))==0){
  		while(OCR2A<248){
  			_delay_ms(100);
  			OCR2A+=10;
  		}
  	}else if(strncmp(lum,"50%",strlen("50%"))==0){
  			if(OCR2A>170){
  		while(OCR2A>170){
  		 	_delay_ms(100); 
  			OCR2A-=10;
  		
  		}
  	}else if(OCR2A<170){
  		while(OCR2A<170){
  			_delay_ms(100);
  			OCR2A+=10;
  		}
  	}
  	}else if(strncmp(lum,"30%",strlen("30%"))==0){
  			if(OCR2A>85){
  		while(OCR2A>85){
  		 	_delay_ms(100); 
  			OCR2A-=10;
  		
  		}
  	}else if(OCR2A<85){
  		while(OCR2A<85){
  			_delay_ms(100);
  			OCR2A+=10;
  		}
  	}
  	}else{
  		OCR2A=0;
  	}
  	
 }else{
  	printf("Caso non compreso\n");
  	
  }	*/
  
  
  

 



}
}
