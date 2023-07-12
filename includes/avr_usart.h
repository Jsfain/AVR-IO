/*
 * File       : AVR_USART.H
 * Version    : 1.0 
 * Target     : Default - ATMega1280
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020 - 2023
 * 
 * Description: Interface for accessing and controlling an USART on an AVR 
 *              microcontroller.
 */

#ifndef AVR_USART_H
#define AVR_USART_H

/*
 ******************************************************************************
 *                                  MACROS
 ******************************************************************************
 */

#ifndef F_CPU
#define F_CPU       16000000UL                   // default target clk freq.
#endif //F_CPU

#define BAUD        9600U                        // decimal baud rate
#define UBRR_VALUE  ((F_CPU) / 16 / (BAUD) - 1)  // calculate value for UBRR

/*
 *******************************************************************************
 *                             FUNCTION PROTOTYPES
 ******************************************************************************
 */

/*
 * ----------------------------------------------------------------------------
 *                                                             INITIALIZE USART
 *                                        
 * Description : Initialize USART on the target device.
 * 
 * Arguments   : void 
 * ----------------------------------------------------------------------------
 */
void usart_Init(void);


/*
 * ----------------------------------------------------------------------------
 *                                                                USART RECEIVE
 *                                         
 * Description : Receive a character via USART on the target device.
 * 
 * Arguments   : void
 * 
 * Returns     : character received by the USART, i.e. value in UDR0.
 * ----------------------------------------------------------------------------
 */
uint8_t usart_Receive(void);


/*
 * ----------------------------------------------------------------------------
 *                                                               USART TRANSMIT
 *                                       
 * Description : Sends a character to another device via USART.
 * 
 * Arguments   : data - data to send via USART.
 * ----------------------------------------------------------------------------
 */
void usart_Transmit(uint8_t data);

#endif //AVR_USART_H
