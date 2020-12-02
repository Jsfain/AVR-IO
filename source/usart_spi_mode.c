/*
***********************************************************************************************************************
*                                                   AVR-GENERAL MODULE
*
* File    : USART_SPI_MODE.C
* Version : 0.0.0.1 
* Author  : Joshua Fain
* Target  : ATMega1280
*
*
* DESCRIPTION:
* Defines standard functions declared in USART.H used for initializing, sending, and recieving data via USART0 on 
* the target device. Most of these are essentially the definitions found in the ATmega datasheet.
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



#include <stdint.h>
#include <avr/io.h>
#include "../includes/usart_spi_mode.h"



/*
***********************************************************************************************************************
 *                                                   INITIALIZE USART
 * 
 * Description  : Initializes USART0 of target device by setting the baud rate, enabling transmit and receive and 
 *                defining data frame format of 8 data bits and 1 stop bit.
***********************************************************************************************************************
*/

void 
USART_SPI_Mode_Init (void)
{


    // Set MOSI, SCK, and SS of SPI port as outputs. MISO is input.
    DDR_USART_SPI = (1 << DD_USART_MOSI) | (1 << DD_USART_SCK) | (1 << DD_USART_SS);
    
    // Make sure SS is high (not asserted) before initializing SPI.
    USART_SPI_PORT |= (1 << USART_SPI_SS);
    
    // Baud rate must be set after TX is enabled.
    UBRR1 = 0;

    // Set USART in SPI master mode. mode, no parity, data frame = 8 data, 1 stop bits
    UCSR1C = (1 << UMSEL11) | (1 << UMSEL10) | (1 << UCSZ11) | (1 << UCSZ10);

    // Enable USART0 receiver and transmitter
    UCSR1B = (1 << RXEN1) | (1 << TXEN1);

    //Set baud rate
    UBRR1H = (uint8_t)((UBRR_SPI_MODE_VALUE) >> 8);
    UBRR1L = (uint8_t)(UBRR_SPI_MODE_VALUE);
}



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
USART_SPI_Mode_Receive (void)
{
    // Wait for data to be received by polling the receive complete flag
    while ( !(UCSR1A & (1 << RXC1))) ;
    
    //return byte received in buffer
    return UDR1;
}



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
USART_SPI_Mode_Transmit (uint8_t data)
{
    //Wait for transmit buffer to be empty by polling Data Register Empty flag
    while( !( UCSR1A & (1 << UDRE0)) ) ;
    
    //Place data byte into buffer to be transmitted via USART
    UDR0 = data;
}


// Added because when using USART for SPI mode requires data read after every
// data transfer. Additionally, a transmit must be performed in order to 
// receive new data as transmit controls the clock.
uint8_t 
USART_SPI_Mode_Data_Transfer (uint8_t data)
{
  USART_SPI_Mode_Transmit (data);
  return USART_SPI_Mode_Receive();
}