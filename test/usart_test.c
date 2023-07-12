/*
 * File       : TEST.C
 * Target     : ATMega1280
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020 - 2023
 * 
 * Program to test USART.C(H).
 */

#include <stdint.h>
#include <avr/io.h>
#include "avr_usart.h"
#include "prints.h"

//
// Initializes the USART and calls different PRINTS functions
// available, multiple times, with various input paramters to print. 
//
int main(void)
{
  usart_Init();

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