#include "SPI.h"

void begin() {
    export_pin(CLK);
    export_pin(MISO);
    export_pin(MOSI);

    set_pin_mode(CLK, OUTPUT); //Clock
    set_pin_mode(MISO, INPUT); //Master In Slave Out
    set_pin_mode(MOSI, OUTPUT); //Master Out Slave In
    set_pin_state(CLK, LOW); //Pull clock to 0
}

void end() {
    unexport_pin(CLK);
    unexport_pin(MISO);
    unexport_pin(MOSI);
}

byte_t transfer(byte_t word) {
    byte_t buf = 0x00;
    for(int i = 0; i < 8; i++) { //Iterate for 1 byte (sizeof word)
        if(word & 0x80)
		    set_pin_state(MOSI, HIGH);
	    else
		    set_pin_state(MOSI, LOW); //Place MOSI bit
        word = word << 1;
        buf = buf << 1;
        buf = buf | read_pin_state(MISO); //Read MISO bit
        set_pin_state(CLK, HIGH); //Pull clock to 1
        usleep(100); //Clock 1 cycle
        set_pin_state(CLK, LOW); //Pull clock to 0
        usleep(100); //Clock 0 cycle
        //50-50 duty cycle clock of 10kHz
	}
    return buf;
}