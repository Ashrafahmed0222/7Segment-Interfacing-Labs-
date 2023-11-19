





/*
********************************************* SSD_INTERFACE.h ************************************************
*  Author:  Ashraf Ahmed Hamed
*  Date:    2/13/2023
*  Layer:   HAL
*  SWC:     SSD
*/



#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#define COMMON_CATHODE 0
#define COMMON_ANODE   1


#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3


#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7

typedef struct {
	u8 TYPE;
	u8 DATA_PORT;
	u8 ENABLE_PORT;
	u8 ENABLE_PIN;
}SSD_CONFIG;



void SSD_voidInitialDataPort (SSD_CONFIG Copy_structConfig);
void SSD_voidSendNumber      (SSD_CONFIG Copy_structConfig, u8 Copy_u8Number);
void SSD_voidEnable          (SSD_CONFIG Copy_structConfig);
void SSD_voidDisable         (SSD_CONFIG Copy_structConfig);
void SSD_voidNumAnimation    (SSD_CONFIG Copy_structConfig, u8 Copy_u8Number);


#endif
