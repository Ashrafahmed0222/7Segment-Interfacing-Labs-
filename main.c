
/*
 * main.c
 *
 *  Created on: Feb 14, 2023
 *      Author: ASHRAF AHMED
 */



#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "SSD_interface.h"

#include <util/delay.h>

int main(void) {

	/********----------------------DISPLAYING (INCREMENT FROM 0 TO 9 & DECREMENT FROM 9 TO 0)------------------------------**********************/

//	SSD_CONFIG SSD1 = { COMMON_CATHODE, SSD_PORTA, 0xFF, DIO_PIN7 };
//	SSD_voidInitialDataPort(SSD1);
//	SSD_voidEnable(SSD1);
//	while (1) {
//
//		for (int i = 0; i <= 9; i++) {
//			SSD_voidSendNumber(SSD1, i);
//			_delay_ms(250);
//		}
//		for (int i = 9; i >= 0; i--) {
//			SSD_voidSendNumber(SSD1, i);
//			_delay_ms(250);
//		}
//
//	}
	/********----------------------COUNTING FROM 0 TO 9------------------------------**********************/

//	SSD_CONFIG SSD1 = {COMMON_CATHODE,SSD_PORTA, 0xFF, DIO_PIN7 };
//	SSD_voidInitialDataPort(SSD1);
//	SSD_voidEnable(SSD1);
//	int i =0;
//	SSD_voidSendNumber(SSD1,i);
//	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN0,DIO_PIN_INPUT);
//	DIO_enumSetPinValue    (DIO_PORTB, DIO_PIN0,DIO_PIN_HIGH);
//
//	while(1)
//	{
//
//
//		if(PINB == 0b00000000)
//		{
//			_delay_ms(150);
//			if(i==9)
//			{
//					i=0;
//					_delay_ms(150);
//					SSD_voidSendNumber(SSD1,i++);
//			}
//			else
//			{
//					_delay_ms(150);
//					SSD_voidSendNumber(SSD1,i++);
//			}
//		}
//
//		SSD_voidSendNumber(SSD1,i);
//
//
//	}
	/********----------------------DISPLAYING LETTERS FROM  a TO f------------------------------**********************/

//SSD_CONFIG SSD1 = {COMMON_CATHODE,SSD_PORTA, 0xFF, DIO_PIN7 };
//SSD_voidInitialDataPort(SSD1);
//SSD_voidEnable(SSD1);
//
//while(1){
//	DIO_enumSetPortValue(SSD_PORTA,0x5F);
//	_delay_ms(700);
//	DIO_enumSetPortValue(SSD_PORTA,0x7C);
//	_delay_ms(700);
//	DIO_enumSetPortValue(SSD_PORTA,0x58);
//	_delay_ms(700);
//	DIO_enumSetPortValue(SSD_PORTA,0x5E);
//	_delay_ms(700);
//	DIO_enumSetPortValue(SSD_PORTA,0x79);
//	_delay_ms(700);
//	DIO_enumSetPortValue(SSD_PORTA,0x71);
//	_delay_ms(700);
//
//
//
//}
	/*-----------only 4 pins from microcontroller to control one SSD----------*/
//	SSD_CONFIG SSD1 = { COMMON_CATHODE, SSD_PORTA, 0xFF, DIO_PIN7 };
//	SSD_voidInitialDataPort(SSD1);
//	SSD_voidEnable(SSD1);
//	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_HIGH);
//	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
//	while (1) {
//
//		for(int i = 1; i<=9; i++){
//			DIO_enumSetPortValue(SSD_PORTA, 0x70+i);
//			_delay_ms(700);
//		}
//
//	}
	/*--------------------------display numbers from 0:99------------------------*/

//	SSD_CONFIG SSD1 = { COMMON_CATHODE, SSD_PORTA, 0xFF, DIO_PIN7 };
//	SSD_voidInitialDataPort(SSD1);
//	SSD_voidEnable(SSD1);
//	SSD_CONFIG SSD2 = { COMMON_CATHODE, SSD_PORTB, 0xFF, DIO_PIN7 };
//	SSD_voidInitialDataPort(SSD2);
//	SSD_voidEnable(SSD2);
//	int j = 0;
//	while (1) {
//
//		for (int i = 0; i <= 9; i++) {
//			SSD_voidSendNumber(SSD1, i);
//			_delay_ms(250);
//			if(i==9){
//			SSD_voidSendNumber(SSD2, ++j);
//			}
//		}
//		if(j == 9){
//			j=-1;
//		}
//	}

	/*-------------------------- Animation task-----------------------------------*/
	SSD_CONFIG SSD1 = { COMMON_CATHODE, SSD_PORTC, 0xFF, DIO_PIN7 };
	SSD_voidInitialDataPort(SSD1);
	SSD_voidEnable(SSD1);
	while (1) {
		for (u8 i = 0; i <= 9; i++) {
			for(u8 j =0; j<=3; j++){
			SSD_voidNumAnimation(SSD1, i);
			}
			_delay_ms(200);
			SSD_voidSendNumber(SSD1, i);
			_delay_ms(200);
		}

	}

	return 0;
}

