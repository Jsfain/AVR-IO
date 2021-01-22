/*
 * File    : TEST.C
 * Author  : Joshua Fain
 * Target  : ATMega1280
 * License : MIT
 * Copyright (c) 2020
 * 
 * Program to test functions in AVR-General.
 */

#include <stdint.h>
#include <avr/io.h>
#include "usart0.h"
#include "prints.h"
#include "spi.h"


int main(void)
{
  usart_init();
  spi_masterInit();

  uint32_t val = 35;

  print_str("\n\n\r");
  print_dec(val);
  print_str(" = ");
  print_bin(val);
  print_str(" = 0x");
  print_hex(val);

  val = 'A';
  print_str("\n\r");
  print_dec(val);
  print_str(" = ");
  print_bin(val);
  print_str(" = 0x");
  print_hex(val);

  val = 5474;
  print_str("\n\r");
  print_dec(val);
  print_str(" = ");
  print_bin(val);
  print_str(" = 0x");
  print_hex(val);

  val = 340293840;
  print_str("\n\r");
  print_dec(val);
  print_str(" = ");
  print_bin(val);
  print_str(" = 0x");
  print_hex(val);

  return 0;
}