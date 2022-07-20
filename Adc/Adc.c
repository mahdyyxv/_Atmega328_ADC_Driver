/*
 * Adc.c
 *
 * Created: 6/28/2022 8:42:47 AM
 *  Author: mahdy
 */ 
#include "Adc.h"
static void M_Adc_SetPin(u8 Local_u8_Pin);

void M_Adc_Init(u8 Local_u8_Pin)
{
	#if   VREF           ==        AVCC
	
	SetBit(ADMUX,6);
	ClrBit(ADMUX,7);
	
	#elif VREF           ==        AREF_PIN
	
	ClrBit(ADMUX, 6);
	ClrBit(ADMUX, 7);
	
	#elif VREF           ==        _1V1
	
	SetBit(ADMUX, 6);
	SetBit(ADMUX, 7);
	
	#endif
	ClrBit(ADMUX, 5);
	
	M_Adc_SetPin(Local_u8_Pin); // To Make Wanted Channel As INPUT
	
	ADCSRA = 0x07;
	
	ADCSRB = ADCSRB & 0xF8;
	
	SetBit(ADCSRA, 5); // to Enable Auto trigger
	SetBit(ADCSRA, 7);  //To Enable Adc Circuit	
}

u16 M_Adc_Read(u8 Local_u8_Pin)
{
	ADMUX = Local_u8_Pin;
	M_Adc_SetPin(Local_u8_Pin);
	SetBit(ADCSRA, 6); // to start conversion;
	
	while( GetBit(ADCSRA, 4) == 0);
	return ADC_READ;
}


static void M_Adc_SetPin(u8 Local_u8_Pin)
{
	ClrBit(_DDRC, Local_u8_Pin);
}