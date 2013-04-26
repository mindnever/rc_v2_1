//
//  ra6963.c
//  rc_v5
//
//  Created by Vladimir Zidar on 11/05/2015.
//  Copyright (c) 2015 mindnever.org. All rights reserved.
//

#include <util/delay.h>
#include <avr/interrupt.h>

#include "ra6963.h"

#include "hardware.h"

static uint16_t maxWaitCount;

#define STA0STA1 ( _BV(LCD_STA0_PIN) | _BV(LCD_STA1_PIN) )
#define STA2STA3 ( _BV(LCD_STA2_PIN) | _BV(LCD_STA3_PIN) )

void RA6963_Init()
{
    IO_DIR_OUT( LCD_CD );
//    IO_DIR_OUT( LCD_CE );
    IO_DIR_OUT( LCD_WR );
    IO_DIR_OUT( LCD_RD );
    IO_DIR_OUT( LCD_PWM );
//    IO_DIR_OUT( LCD_RST );
    
//    IO_PIN_HIGH( LCD_CE );
    IO_PIN_LOW( LCD_PWM );

    IO_PIN_HIGH( LCD_WR );
    IO_PIN_HIGH( LCD_RD );
 
    IO_PIN_LOW( LCD_CD );

    LCD_PWM_STOP();
    
//    IO_PIN_LOW( LCD_RST );
//    
//    _delay_us( 100 );
//    
//    IO_PIN_HIGH( LCD_RST );
}

uint8_t RA6963_Read( )
{
    RA6963_Wait();
    
    LCD_DATA_DIR_IN();
    LCD_DATA_OUT(0x00); // turn off pullups
    
    IO_PIN_LOW( LCD_CD ); // data

    uint8_t sreg = SREG;
    cli();

//    IO_PIN_LOW( LCD_CE );
    IO_PIN_LOW( LCD_RD );

    __asm("nop"); // 62.5ns
    __asm("nop"); // 62.5ns

    
    uint8_t ret = LCD_DATA_IN();

    SREG = sreg;
    
    IO_PIN_HIGH( LCD_RD );
//    IO_PIN_HIGH( LCD_CE );
    
    
    IO_PIN_HIGH( LCD_CD ); // back to cmd

    return ret;
}

void RA6963_Write( uint8_t data )
{
    RA6963_Wait();

    IO_PIN_LOW( LCD_CD ); // data
    
    LCD_DATA_OUT( data );

    LCD_DATA_DIR_OUT();
    
    __asm("nop");

//    IO_PIN_LOW( LCD_CE ); // enable
    IO_PIN_LOW( LCD_WR ); // write

    __asm("nop\n nop\n nop\n nop\n");
    
    IO_PIN_HIGH( LCD_WR );
//    IO_PIN_HIGH( LCD_CE );

}

void RA6963_Command( uint8_t cmd )
{
    RA6963_Wait();

    IO_PIN_HIGH( LCD_CD ); // command
    
    LCD_DATA_OUT( cmd );
    LCD_DATA_DIR_OUT();
    
    __asm("nop");

//    IO_PIN_LOW( LCD_CE ); // enable
    IO_PIN_LOW( LCD_WR ); // write

    __asm("nop\n nop\n");
    
    IO_PIN_HIGH( LCD_WR );
//    IO_PIN_HIGH( LCD_CE );
}

void RA6963_DataCommand( uint8_t cmd, uint8_t data )
{
    RA6963_Write( data );
    RA6963_Command( cmd );
}
void RA6963_DataCommand2( uint8_t cmd, uint8_t data1, uint8_t data2 )
{
    RA6963_Write( data1 );
    RA6963_Write( data2 );
    RA6963_Command( cmd );
}

void RA6963_AddressCommand( uint8_t cmd, uint16_t address )
{
    RA6963_DataCommand2( cmd, address & 0xff, address >> 8 );
}

uint8_t RA6963_DataReadCommand( uint8_t cmd )
{
    RA6963_Command( cmd );

    return RA6963_Read( );
}


uint8_t RA6963_Wait()
{
    uint16_t w = 0;
    
    IO_PIN_HIGH( LCD_CD ); // status (command)
    
//    __asm("nop"); // 62.5ns

    IO_DIR_IN( LCD_STA0 );
    IO_DIR_IN( LCD_STA1 );
    
//    IO_PIN_LOW( LCD_CE );
    IO_PIN_LOW( LCD_RD );
    
    while( ( ( (IO_PIN_READ( LCD_STA0 ) | IO_PIN_READ( LCD_STA1 )) != STA0STA1 ) ) && (w < 1000) )
    {
        ++w;
    }

    IO_PIN_HIGH( LCD_RD );
//    IO_PIN_HIGH( LCD_CE );

    if(w > maxWaitCount)
    {
        maxWaitCount = w;
    }
    
    return 0;
}

uint16_t RA6963_GetMaxWaitCount( )
{
    return maxWaitCount;
}

void RA6963_Backlight( uint8_t val )
{
    LCD_PWM_SET( val );
    
    if(val > 0)
    {
        LCD_PWM_START();
    }
    else
    {
        LCD_PWM_STOP();
    }
}

