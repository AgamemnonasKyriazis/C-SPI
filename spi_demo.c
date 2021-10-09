#include "SPI.h"

int main() {
    signal(SIGINT, handle_interrupt);
    begin();
    export_pin("5");
    set_pin_mode("5", OUTPUT);
    while(1) {
	    set_pin_state("5", LOW);
    	transfer(0x01);
    	int x = transfer(0x80)<<8 | transfer(0);
    	printf("%x\n", x);
    	set_pin_state("5", HIGH);
	    sleep(2);
    }
}
