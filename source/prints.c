/*
 * File    : PRINTS.C
 * Version : 0.0.0.2
 * Author  : Joshua Fain
 * Target  : ATMega1280
 * License : MIT
 * Copyright (c) 2020
 * 
 * Implementation of PRINTS.H
 */

#include <stdint.h>
#include <avr/io.h>
#include "prints.h"
#include "usart0.h"


/*
 ******************************************************************************
 *                                  FUNCTIONS 
 ******************************************************************************
 */

/*
 * ----------------------------------------------------------------------------
 *                                    PRINT UNSIGNED DECIMAL (BASE-10) INTEGERS 
 * 
 * Description : Prints unsigned decimal integer form of argument to screen.
 * 
 * Arguments   : num     Unsigned integer to be printed to the screen.
 * 
 * Returns     : void
 * ----------------------------------------------------------------------------
 */

void print_dec (uint32_t num)
{
  char    arr[10];
  uint8_t len = 0;

  //
  // 1) Divide number by 10 and load its remainder into the array. 
  // 2) Update the value of the number by dividing itself by 10. 
  // 3) Repeat until number is 0. 
  // Notes: - the array will be loaded in reverse order.
  //        - the '+ 48' is to convert numbers to ascii. 
  //
  do
  {
    arr[len] = (num % 10) + 48;
    num /= 10;
    len++;  
  }
  while (num > 0);

  for (int i = len-1; i >= 0; i--)
    usart_transmit (arr[i]);
}


/*
 * ----------------------------------------------------------------------------
 *                                                 PRINT BINARY FORM OF INTEGER 
 *                                        
 * Description : Prints the binary form of the integer argument to the screen.
 * 
 * Argument    : num     Unsigned integer to be printed to the screen.
 * 
 * Returns     : void 
 * 
 * Notes       : The function prints the number as space-separated groups of 
 *               4-bits (nibbles). Only the number of 4-bit groups necessary to
 *               display the value will be printed to the screen.
 * ----------------------------------------------------------------------------
 */

void print_bin (uint32_t num)
{
    //Determine number binary digits required to represent the number.
    uint8_t len = 4;
    
    if(num < 0x10)              len = 4;
    else if(num < 0x100)        len = 8;
    else if(num < 0x1000)       len = 12;
    else if(num < 0x10000)      len = 16;
    else if(num < 0x100000)     len = 20;
    else if(num < 0x1000000)    len = 24;
    else if(num < 0x10000000)   len = 28;
    else if(num <= 0xFFFFFFFF)  len = 32;

    char bin[len];

    //initialize each digit to '0'.
    for (uint8_t i = 0; i < len; i++) 
      bin[i] = '0'; 
    
    uint32_t result = num;
    uint8_t  remainder = 0;

    for (uint8_t i = 0; i < len; i++)
    {
        remainder = result % 2;
        result = result / 2;

        if (remainder == 0) 
            bin[i] = '0';
        else 
            bin[i] = '1';
    }

    // print characters in binary array. 
    // print a space every 4 bits.
    for (int i = len-1; i >= 0; i--)
    {
        usart_transmit (bin[i]);
        if ((i % 4) == 0) 
          usart_transmit (' ');
    }
}


/*
 * ----------------------------------------------------------------------------
 *                                         PRINT HEXADECIMAL FORM OF AN INTEGER
 *                                       
 * Description : Prints the hexadecimal form of unsigned integer argument to
 *               the screen.
 * 
 * Argument    : num     Unsigned integer to be printed to the screen.
 * 
 * Returns     : void
 * ----------------------------------------------------------------------------
 */

void print_hex (uint32_t num)
{
    //Determine number of hexadecimal digits required to represent the number.
    uint8_t len = 2;
    
    if (num < 0x100)           len = 2;
    else if(num < 0x1000)      len = 3;
    else if(num < 0x10000)     len = 4;
    else if(num < 0x100000)    len = 5;
    else if(num < 0x1000000)   len = 6;
    else if(num < 0x10000000)  len = 7;
    else if(num <= 0xFFFFFFFF) len = 8;

    char hex[len];
    
    // initialize each digit to '0'.
    for (int i = 0; i < len; i++) 
      hex[i] = '0';
    
    uint32_t result = num;
    uint8_t  remainder = 0;

    for (int i = 0; i < len; i++)
    {
        remainder = result % 16;
        result = result / 16;

        //convert to ascii characters.
        if ((remainder < 10) && (remainder >= 0))
          hex[i] = remainder + 48; //ascii numbers
        else if ((remainder >= 10) && (remainder <= 16)) 
          hex[i] = (remainder - 10) + 65; //ascii letters
    }
    
    //print characters in hexadecimal array.
    for (int i = len-1; i >= 0; i--) 
      usart_transmit (hex[i]);
}    


/*
 * ----------------------------------------------------------------------------
 *                                                               PRINT C-STRING
 *                                       
 * Description : Prints the C-string passed as the argument.
 * 
 * Argument    : str     Pointer to a null-terminated char array (i.e. 
 *                       c-string), that will be printed to the screen. 
 * 
 * Notes       : Strings up to 999 characters + '\0' (null character) can
 *               currently be handled by this function.
 * ----------------------------------------------------------------------------
 */

void print_str(char * str)
{
    int i = 0;
    while(str[i] != '\0' && i < 1001)
    {
        usart_transmit(str[i]);
        i++;
    };
}

