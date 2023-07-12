/*
 * File       : ADC_TEST.C
 * Target     : ATMega1280
 * Compiler   : AVR-GCC 9.3.0
 * Downloader : AVRDUDE 6.3
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020 - 2023
 * 
 * Program to test functions in AVR_ADC.C(H).
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "avr_usart.h"
#include "prints.h"
#include "adc.h"


int main(void)
{
  usart_Init();
  adc_Init();

  uint16_t ADCR;

  // only need this one if auto triggering is enabled.
  #if AUTO_TRIG_EN
  ADCSRA |= (1<<ADSC);
  #endif // AUTO_TRIG_EN

  // loop waits for key input and then triggers.
  for (;;){
    usart_Transmit(usart_Receive());
    #if (!AUTO_TRIG_EN)
    ADCSRA |= (1 << ADSC);  // need this is auto triggering is not enabled.
    #endif // (!AUTO_TRIG_EN)
    while (!(ADCSRA & (1 << ADIF)))
      ;
    
    uint8_t tempLow = ADCL;
    ADCR = ADCH;
    ADCR <<= 8;
    ADCR |= tempLow;
    
    print_Str("\n\r");
    // print the voltage
    ADC_toFloat(ADCR);
  }

  return 0;
}