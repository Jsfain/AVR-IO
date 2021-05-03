# AVR-General
Repository for general AVR modules


## Overview
This repository is intended for some general AVR-specific functions and capabilities.


### Currently Included
1) SPI.C / SPI.H : Source/header for interacting with the SPI port of an AVR microcontroller.
2) USART.C / USART.H : Source/header for interacting with USART port of an AVR microcontroller.   
3) PRINTS.C / PRINTS.H : Source/header for printing integers (decimal, hex, binary) and strings to screen via an AVR microcontrollers USART.
4) ADC.C / ADC.H : Source/header for the analog to digital converter of an AVR microcontroller.


## Technology Details
* TARGET     : ATmega1280, but portable to other AVR targets with PORT reassignments, provided sufficient resources available.  
* LANGUAGE   : C
* COMPILER   : AVR-GCC 9.3.0
* DOWNLOADER : AVRDUDE 6.3
* Compiler and downloader used are available with the [AVR-Toolchain from Homebrew](https://github.com/osx-cross/homebrew-avr).


## Implementation
See the source/header files for specifics.


## Who may use
Anyone.


## How To Use
Clone the repo or copy the files, compile, and download to the AVR microcontroller.


## License
[GNU GPLv3](https://github.com/Jsfain/AVR-General/blob/master/LICENSE)
