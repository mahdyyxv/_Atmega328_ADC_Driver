/*
 * Adc.h
 *
 * Created: 6/28/2022 8:42:57 AM
 *  Author: mahdy
 */ 


#ifndef ADC_H_
#define ADC_H_



/*********************************_INCLUDES_*********************************/
#include "AdcCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*********************************_MACROS_*********************************/
#define    AVCC       1
#define    AREF_PIN   2
#define    _1V1       3

#define    ADC0       0
#define    ADC1       1
#define    ADC2       2
#define    ADC3       3
#define    ADC4       4
#define    ADC5       5

/*********************************_PROTOTYPE_*********************************/
void M_Adc_Init(u8); /* Send channel to Init For ex (ADC0)*/ 
u16  M_Adc_Read(u8); /* Send channel to Read For ex (ADC0)*/ 


#endif /* ADC_H_ */