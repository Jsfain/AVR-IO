/*
 * File    : PRINTS.H
 * Version : 0.0.0.2
 * Author  : Joshua Fain
 * Target  : ATMega1280
 * License : MIT
 * Copyright (c) 2020
 * 
 * Interface for some print functions used to print strings and unsigned
 * integers in decimal, binary, and hex formats.
 */

#ifndef PRINTS_H
#define PRINTS_H


/*
 ******************************************************************************
 *                           FUNCTION PROTOTYPES   
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

void print_dec (uint32_t num);


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

void print_bin (uint32_t num);


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

void print_hex (uint32_t num);


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

void print_str (char * str);

#endif //PRINTS_H
