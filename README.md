# AVR-IO
Repository for some general AVR I/O modules

## Overview
This repo is used to hold some AVR-specific I/O source and header files used used in various other projects. The functionality provided for in the files is limited to what's needed in other projects and does not utilize the full capabilities of the I/O ports. Note, also, these are intended for use against an AVR ATmega 1280 microcontroller but should be easily portable to other AVR devices.

## AVR-IO Source and Header File
1. **AVR_SPI.C(H)** - For using an SPI port on an AVR microcontroller.
2. **AVR_USART.C(H)** - For using an USART port on an AVR microcontroller.   

## Technology Details
The below tech details were used to build/use these files, though they should be easily portable to other AVR targets with similar features/capabilties.

* TARGET: ATmega1280
* LANGUAGE: C
* COMPILER: AVR-GCC 9.3.0
* DOWNLOADER: AVRDUDE 6.3
* Compiler and downloader used are available with the [AVR-Toolchain from Homebrew](https://github.com/osx-cross/homebrew-avr).

## Implementation
See the source and header files for descriptions of the I/O settings, functions, and capabilities.

## Who may use
Anyone

## How To Use
Copy the necessary files, compile, and download to the AVR microcontroller.

## License
[GNU GPLv3](https://github.com/Jsfain/AVR-IO/blob/master/LICENSE)
