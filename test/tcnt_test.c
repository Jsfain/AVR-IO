/*
 * File       : TCNT_TEST.C
 * Target     : ATMega1280
 * Compiler   : AVR-GCC 9.3.0
 * Downloader : AVRDUDE 6.3
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020, 2021
 * 
 * Program to test functions in the AVR-General source files.
 */

#include <avr/io.h>
#include "usart0.h"
#include "prints.h"

#define OC3C PE5

int main(void)
{
  usart_Init();

  print_Str("\n\rHELLO");

  // OC3A - PE3
  DDRE |= 1 << DDE3;

  TCCR3A |= (TCCR3A & ~(1 << COM3A1)) | 1 << COM3A0;
  print_Str("\n\rTCCR3A = 0b");print_Bin(TCCR3A);

  TCCR3B |= 1 << CS32 | 0 << CS31 | 0 << CS30;

  for (;;){
    if (TIFR3 & (1 << OCF3A)) {
      print_Str("\n\rOC3 = 0b"); print_Bin(TOV3);
     // print_Str("\n\rTCNT3 = 0b");print_Bin(TCNT3H);print_Bin(TCNT3L);
    }
    else 
      print_Str("NOT");
  }

}