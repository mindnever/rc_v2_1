//
//  ra6963.h
//  rc_v5
//
//  Created by Vladimir Zidar on 11/05/2015.
//  Copyright (c) 2015 mindnever.org. All rights reserved.
//

#ifndef __rc_v5__ra6963__
#define __rc_v5__ra6963__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void RA6963_Init();
void RA6963_Backlight( uint8_t val );

void RA6963_Command( uint8_t cmd );

void RA6963_DataCommand( uint8_t cmd, uint8_t data );
void RA6963_DataCommand2( uint8_t cmd, uint8_t data1, uint8_t data2 );
void RA6963_AddressCommand( uint8_t cmd, uint16_t address );
uint8_t RA6963_DataReadCommand( uint8_t cmd );

void RA6963_Write( uint8_t data );
uint8_t RA6963_Read( );

uint8_t RA6963_Wait( );

uint16_t RA6963_GetMaxWaitCount( );

#ifdef __cplusplus
}
#endif


#define T6963_COMMAND_MASK 0xf0


#define T6963_SET_CURSOR_POINTER			0x21
#define T6963_SET_OFFSET_REGISTER			0x22
#define T6963_SET_ADDRESS_POINTER			0x24

#define T6963_SET_TEXT_HOME_ADDRESS			0x40
#define T6963_SET_TEXT_AREA					0x41
#define T6963_SET_GRAPHIC_HOME_ADDRESS		0x42
#define T6963_SET_GRAPHIC_AREA				0x43

#define T6963_MODE_SET						0x80
    #define T6963_MODE_OR                   0x00
    #define T6963_MODE_EXOR                 0x01
    #define T6963_MODE_AND                  0x03
    #define T6963_MODE_TEXT_ATTR            0x04
    #define T6963_CG_INT                    0x00
    #define T6963_CG_EXT                    0x08

#define T6963_DISPLAY_MODE					0x90
	#define T6963_CURSOR_BLINK_ON			0x01
	#define T6963_CURSOR_DISPLAY_ON			0x02
	#define T6963_TEXT_DISPLAY_ON			0x04
	#define T6963_GRAPHIC_DISPLAY_ON		0x08				


#define T6963_CURSOR_PATTERN_SELECT			0xA0
	#define T6963_CURSOR_1_LINE				0x00
	#define T6963_CURSOR_2_LINE				0x01
	#define T6963_CURSOR_3_LINE				0x02
	#define T6963_CURSOR_4_LINE				0x03
	#define T6963_CURSOR_5_LINE				0x04
	#define T6963_CURSOR_6_LINE				0x05
	#define T6963_CURSOR_7_LINE				0x06
	#define T6963_CURSOR_8_LINE				0x07

#define T6963_SET_DATA_AUTO_WRITE			0xB0
#define T6963_SET_DATA_AUTO_READ			0xB1
#define T6963_AUTO_RESET					0xB2


#define T6963_DATA                          0xC0
    #define T6963_WRITE                     0x00
    #define T6963_READ                      0x01
    #define T6963_ADP_INC                   0x00
    #define T6963_ADP_DEC                   0x02
    #define T6963_ADP_KEEP                  0x04


#define T6963_SCREEN_PEEK					0xE0
#define T6963_SCREEN_COPY					0xE8

#define T6963_BIT_SET                       0xF8
#define T6963_BIT_CLEAR                     0xF0


#endif /* defined(__rc_v5__ra6963__) */
