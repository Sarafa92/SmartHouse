#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <string.h>

#include "../arduino/dimmer/dimmerpiu.h"
#include "../arduino/dimmer/dimmermeno.h"

typedef struct {

char* nomeController;
char* nomeSwitch;
int indexArray;

}id_pin;
