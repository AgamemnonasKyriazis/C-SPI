# C-SPI
## Header file for controlling SPI slave (secondary) devices with a raspberry-pi as master (primary) device.
SPI demo file contains an example code of controlling the MCP3008 chip and reading CH0 of MCP3008.
You need to initialize and control the CS pins on your own.
The begin() function initializes CLK, MISO and MOSI pins.
transfer() send a byte of data though MOSI and returns a byte of data back to the user through MISO.
Finally end() function closes CLK, MISO and MOSI file descriptors. All CS pins need to be un-initialized by the user manually using the unexport_pin() function.

Compile using gcc spi_demo.c SPI.c gpio-control.c linked-list.c

The gpio-control packages can be found here: https://github.com/AgamemnonasKyriazis/RPI-GPIO-control-in-C

Please fill this form to help me improve: https://forms.gle/YRDhkPZpNJ5Wc52T7
