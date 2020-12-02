/*
***********************************************************************************************************************
*                                                   AVR-GENERAL MODULE
*
* File    : USART_SPI_MODE.H
* Version : 0.0.0.1 
* Author  : Joshua Fain
* Target  : ATMega1280
*
*
* DESCRIPTION:
* Defines CPU frequency and baud rate macros, as well as declares the standard functions defined in USART.C for 
* initializing, sending, and recieving data via USART0 on the target device. 
* 
*
* FUNCTIONS:
*   (1) void    USART_Init (void)
*   (2) uint8_t USART_Receive (void)
*   (3) void    USART_Transmit (uint8_t data)
*                                   
*
*                                                       MIT LICENSE
*
* Copyright (c) 2020 Joshua Fain
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
* documentation files (the "Software"), to deal in the Software without restriction, including without limitation the 
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
* permit ersons to whom the Software is furnished to do so, subject to the following conditions: The above copyright 
* notice and this permission notice shall be included in all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
***********************************************************************************************************************
*/


#ifndef USART_SPI_MODE_H
#define USART_SPI_MODE_H


/*
***********************************************************************************************************************
 *                                                       MACROS
***********************************************************************************************************************
*/


//Specify clock frequency of target device if not already defined.
#ifndef F_CPU 
#define F_CPU   16000000UL
#endif //F_CPU


// Defining SCK for USART in SPI mode is done exactly
// the same way as defining the BAUD rate for the USART
// in Synchronous Master Mode.
#define USART_SCK_FREQ  250000 //Hz


// Calculate the value to load into UBRR (UBRRH & UBRRL)
// which also defines the SPI mode SCK rate.
#define UBRR_SPI_MODE_VALUE   (F_CPU/2/USART_SCK_FREQ) - 1 


// SPI Data Direction Register (DDR) macros.
#define DDR_USART_SPI     DDRJ
#define DD_USART_SS       DDJ3
#define DD_USART_SCK      DDJ2
#define DD_USART_MOSI     DDJ1
#define DD_USART_MISO     DDJ0


// SPI Port Assignment macros.
#define USART_SPI_PORT        PORTJ
#define USART_SPI_SS          PJ3
#define USART_SPI_SCK         PJ2
#define USART_SPI_MOSI        PJ1
#define USART_SPI_MISO        PJ0



/*
***********************************************************************************************************************
 *                                                       FUNCTIONS
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
 *                                                   INITIALIZE USART
 * 
 * Description  : Initializes USART0 of target device by setting the baud rate, enabling transmit and receive and 
 *                defining data frame format of 8 data bits and 1 stop bit.
***********************************************************************************************************************
*/

void 
USART_SPI_Mode_Init (void);




/*
***********************************************************************************************************************
 *                                               RECEIVE BYTE VIA USART
 * 
 * Description  : Standard USART receive function used to get the byte received in USART0 by polling the RXC0 flag and
 *                then returning the byte in UDR0.
 * 
 * Argument     : void
 * 
 * Returns      : data byte received in UDR0.
***********************************************************************************************************************
*/

uint8_t 
USART_SPI_Mode_Receive (void);



/*
***********************************************************************************************************************
 *                                               TRANSMIT BYTE VIA USART
 * 
 * Description  : Standard USART transmit function used to transmit a data byte by polling the UDRE0 flag. When the 
 *                flag is set, UDR0 is empty and a new data byte can be loaded into UDR0 to be sent by USART. 
 * 
 * Argument     : byte    Unsigned data byte to send via USART.
***********************************************************************************************************************
*/

void 
USART_SPI_Mode_Transmit (uint8_t data);



// Added because when using USART for SPI mode requires data read after every
// data transfer. Additionally, a transmit must be performed in order to 
// receive new data as transmit controls the clock.
uint8_t 
USART_SPI_Mode_Data_Transfer (uint8_t data);

#endif //USART_SPI_MODE_H