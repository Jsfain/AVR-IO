/*
 * File       : ADC.C
 * Target     : Default - ATMega1280
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020, 2021
 * 
 * Implmentation of ADC.H.
 */

#include <stdint.h>
#include <avr/io.h>
#include "prints.h"
#include "ADC.H"

void adc_Init()
{
  // Ensure Power Reduction ADC bit, PRADC, is disabled (default).
  PRR0 &= ~(1 << PRADC);

  // AVCC as reference. REFS1 = 0 REFS0 = 1.
  ADMUX |= (1 << REFS0); 

  #if AUTO_TRIG_EN
  ADCSRA |= (1 << ADATE);       // Enable Auto Triggering.
  ADCSRB &= AUTO_TRIG_SRC_MSK;  // Specify source for auto trigger.
  #endif // AUTO_TRIG_EN

  //
  // ADC clock must be 50kHz to 200kHz. With 16MHz system clock this is 
  // only achievable with ADC prescaler of 128 -> clk/128 = 125kHz.
  //
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  // Enable the ADC.
  ADCSRA |= (1 << ADEN);
}

//
// converts the value in the ADC data register to a decimal number representing
// a positive voltage.
//
void ADC_toFloat(uint16_t adcVal)
{
  uint16_t div = ADC_REF_V * adcVal;
  
  print_Dec(div / ADC_BIT_RES);
  if (div % ADC_BIT_RES) {
    div %= ADC_BIT_RES;
    print_Str(".");

    for (uint8_t cnt = 0; (cnt < MAX_DEC_DIG) && (div % ADC_BIT_RES); ++cnt) {
      div *= 10;
      print_Dec(div / ADC_BIT_RES);
      div %= ADC_BIT_RES;
    }
  }
}
