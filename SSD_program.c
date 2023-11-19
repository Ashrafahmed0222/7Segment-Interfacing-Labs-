
/*
 ********************************************* SSD_PROGRAM.h ************************************************
 *  Author:  Ashraf Ahmed Hamed
 *  Date:    2/13/2023
 *  Layer:   HAL
 *  SWC:     SSD
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------------------------------*/

#include "DIO_interface.h"
/*--------------------------------------*/

#include "SSD_interface.h"
#include "SSD_private.h"
#include <util/delay.h>

static u8 Local_u8SSD_Numbers[10] = SSD_NUMBER_ARR;
static u32 Local_u16SSD_NUMBERS_IN_BINARY[10] = SSD_NUMBER_IN_BINARY;

void SSD_voidInitialDataPort(SSD_CONFIG Copy_structConfig) {
	DIO_enumSetPortDirection(Copy_structConfig.DATA_PORT, 0xFF);
}

/*-----------------------------------------------------------------------*/

void SSD_voidSendNumber(SSD_CONFIG Copy_structConfig, u8 Copy_u8Number) {
	if (Copy_structConfig.TYPE == COMMON_CATHODE) {
		DIO_enumSetPortValue(Copy_structConfig.DATA_PORT,
				Local_u8SSD_Numbers[Copy_u8Number]);
	} else if (Copy_structConfig.TYPE == COMMON_ANODE) {
		DIO_enumSetPortValue(Copy_structConfig.DATA_PORT,
				~(Local_u8SSD_Numbers[Copy_u8Number]));
	}
}

/*-------------------------------------------------------------------------*/

void SSD_voidEnable(SSD_CONFIG Copy_structConfig) {
	if (Copy_structConfig.TYPE == COMMON_CATHODE) {
		DIO_enumSetPinDirection(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_LOW);
	} else if (Copy_structConfig.TYPE == COMMON_ANODE) {
		DIO_enumSetPinDirection(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_HIGH);
	}
}

/*------------------------------------------------------------------------*/

void SSD_voidDisable(SSD_CONFIG Copy_structConfig) {
	if (Copy_structConfig.TYPE == COMMON_CATHODE) {
		DIO_enumSetPinDirection(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_HIGH);
	} else if (Copy_structConfig.TYPE == COMMON_ANODE) {
		DIO_enumSetPinDirection(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue(Copy_structConfig.DATA_PORT,
				Copy_structConfig.ENABLE_PIN, DIO_PIN_LOW);
	}
}

/*----------------------------------------------------------------------------*/

void __attribute__((optimize("00")))SSD_voidNumAnimation(SSD_CONFIG Copy_structConfig, u8 Copy_u8Number) {
	u16 bit = 0;
	u32 num = Local_u16SSD_NUMBERS_IN_BINARY[Copy_u8Number];
	u16 ctr = 1;
		while (num != 0) {
			bit = num % 10;
			num = num / 10;
			if (bit == 1) {
				DIO_enumSetPortValue(Copy_structConfig.DATA_PORT, ctr);
				_delay_ms(200);
			}
			ctr = ctr << 1;
		}

}

