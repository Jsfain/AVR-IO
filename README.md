# AVR-IO
Repository for general AVR I/O modules

## Overview
This repository is used to hold some AVR-specific I/O source/header files to be used in various other projects.

## AVR-IO Source/Header Files
1. **AVR_SPI.C(H)** - For using an SPI port on an AVR microcontroller.
2. **AVR_USART.C(H)** - For using an USART port on an AVR microcontroller.   
3. **AVR_ADC.C(H)** - For using an analog-to-digital converter on an AVR microcontroller.

## Additional files in repo
1. **PRINTS.C(H)** Source/Header for printing unsigned integers (decimal, hex, binary) and strings. This is platform independent, and included here only for testing purposes. In the current configuration, it interacts with an AVR microcontroller through the USART port via AVR_USART.C(H). These files are maintained in the [C-helpers repo](https://github.com/Jsfain/C-Helpers).   

## Technology Details
Below are the technology details used in these projects. The I/O capabilites should be easily portable to other AVR targets with similar features/capabilties once proper port reassignments have been completed, appropriate to the microcontroller being used.

* TARGET: ATmega1280 - reassignment of the PORTs appropriate to the version of microcontroller used.  
* LANGUAGE: C
* COMPILER: AVR-GCC 9.3.0
* DOWNLOADER: AVRDUDE 6.3
* Compiler and downloader used are available with the [AVR-Toolchain from Homebrew](https://github.com/osx-cross/homebrew-avr).


## Implementation
See the source/header files for descriptions of the capabilities of each .


## Who may use
Anyone


## How To Use
Clone the repo or copy the files, compile, and download to the AVR microcontroller.


## License
[GNU GPLv3](https://github.com/Jsfain/AVR-IO/blob/master/LICENSE)
