# AVR-IO
Repository for general AVR modules

## Overview
This repository is intended for some general AVR-specific functions and capabilities.


### Currently Included
1. **AVR_SPI.C(H)** - Source/Header for interacting with the SPI port of an AVR microcontroller.
2. **AVR_USART.C(H)** - Source/Header for interacting with USART port of an AVR microcontroller.   
3. **AVR_ADC.C(H)** - Source/Header for interacting with the analog-to-digital converter of an AVR microcontroller.

### Additional files in repo
1. **PRINTS.C(H)** Source/Header for printing unsigned integers (decimal, hex, binary) and strings. This is platform independent and here only interacts with an AVR microcontroller through the usart port via AVR_USART.C(H). This is maintained in the [C-helpers repo](https://github.com/Jsfain/C-Helpers).   

## Technology Details
* TARGET: ATmega1280 - Intended to be easily portable to other AVR targets with reassignment of the PORTs appropriate to the version of microcontroller used.  
* LANGUAGE: C
* COMPILER: AVR-GCC 9.3.0
* DOWNLOADER: AVRDUDE 6.3
* Compiler and downloader used are available with the [AVR-Toolchain from Homebrew](https://github.com/osx-cross/homebrew-avr).


## Implementation
See the source/header files.


## Who may use
Anyone


## How To Use
Clone the repo or copy the files, compile, and download to the AVR microcontroller.


## License
[GNU GPLv3](https://github.com/Jsfain/AVR-IO/blob/master/LICENSE)
