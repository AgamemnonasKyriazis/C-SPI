#ifndef SPI

#include "gpio-control.h"

#define CLK "11"
#define MISO "9"
#define MOSI "10"

typedef unsigned char byte_t; 

void begin();
void end();

byte_t transfer(byte_t word);

#endif