/*
 * File       : ADC.H
 * Target     : ATMega1280
 * Compiler   : AVR-GCC 9.3.0
 * Downloader : AVRDUDE 6.3
 * License    : GNU GPLv3
 * Author     : Joshua Fain
 * Copyright (c) 2020, 2021
 * 
 * Interface for implementing the ATMega's ADC.
 */

#ifndef ADC_H
#define ADC_H

#define AUTO_TRIG_EN  1           // set to enable auto triggering

#if AUTO_TRIG_EN
#define AUTO_TRIG_SRC_MSK 0b11111000  // source is free running.
#endif // AUTO_TRIG_EN

#define ADC_REF_V   5             // voltage reference value
#define ADC_BIT_RES 1024          // 10-bit resolution
#define MAX_DEC_DIG 8             // max number of decimal digits to display

void adc_Init();
void ADC_toFloat(uint16_t val);   

#endif // ADC_H
