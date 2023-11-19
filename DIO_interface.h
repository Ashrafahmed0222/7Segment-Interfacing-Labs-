/*
********************************************* DIO_interface.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/9/2023
*  Layer:   M_CAL
*  SWC:     DIO/GPIO
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7






DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction );
DIO_ErrorStatus DIO_enumSetPinValue     (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value     );
DIO_ErrorStatus DIO_enumGetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 *Copy_PtrData         );
DIO_ErrorStatus DIO_enumTogglePinValue  (u8 Copy_u8PORT, u8 Copy_u8PIN                      );



DIO_ErrorStatus DIO_enumSetPortDirection (u8 Copy_u8PORT, u8 Copy_u8Direction      );
DIO_ErrorStatus DIO_enumSetPortValue     (u8 Copy_u8PORT, u8 Copy_u8Value          );
DIO_ErrorStatus DIO_enumGetPortValue         (u8 Copy_u8PORT , u8 *Copy_PortPtrData);
DIO_ErrorStatus DIO_enumTogglePortValue  (u8 Copy_u8PORT                           );




#endif
