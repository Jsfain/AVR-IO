/*
 * File    : TEST.C
 * Author  : Joshua Fain
 * Target  : ATMega1280
 * License : MIT
 * Copyright (c) 2020
 * 
 * Program to test functions in the AVR-General source files.
 */

#include <stdint.h>
#include <avr/io.h>
#include "usart0.h"
#include "prints.h"
#include "spi.h"


//
// Initializes the USART and SPI and calls the different PRINTS functions
// available, multiple times with various input paramters to print. 
//
int main(void)
{
  usart_Init();
  spi_MasterInit();

  uint32_t val = 35;
  print_Str("\n\n\rStarting Test");
  print_Str("\n\n\r");
  print_Dec(val);
  print_Str(" = ");
  print_Bin(val);
  print_Str(" = 0x");
  print_Hex(val);

  val = 'A';
  print_Str("\n\r");
  print_Dec(val);
  print_Str(" = ");
  print_Bin(val);
  print_Str(" = 0x");
  print_Hex(val);

  val = 5474;
  print_Str("\n\r");
  print_Dec(val);
  print_Str(" = ");
  print_Bin(val);
  print_Str(" = 0x");
  print_Hex(val);

  val = 340293840;
  print_Str("\n\r");
  print_Dec(val);
  print_Str(" = ");
  print_Bin(val);
  print_Str(" = 0x");
  print_Hex(val);

  val = 0;
  print_Str("\n\r");
  print_Dec(val);
  print_Str(" = ");
  print_Bin(val);
  print_Str(" = 0x");
  print_Hex(val);

  return 0;
}