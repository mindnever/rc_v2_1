/* Name: oddebug.h
 * Project: AVR library
 * Author: Christian Starkjohann
 * Creation Date: 2005-01-16
 * Tabsize: 4
 * Copyright: (c) 2005 by OBJECTIVE DEVELOPMENT Software GmbH
 * License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)
 */

#ifndef __oddebug_h_included__
#define __oddebug_h_included__

/*
General Description:
This module implements a function for debug logs on the serial line of the
AVR microcontroller. Debugging can be configured with the define
'DEBUG_LEVEL'. If this macro is not defined or defined to 0, all debugging
calls are no-ops. If it is 1, DBG1 logs will appear, but not DBG2. If it is
2, DBG1 and DBG2 logs will be printed.

A debug log consists of a label ('prefix') to indicate which debug log created
the output and a memory block to dump in hex ('data' and 'len').
*/

#include <stdint.h>

#ifdef __AVR__
#include <avr/io.h>
#endif

#ifndef F_CPU
#   define  F_CPU   12000000    /* 12 MHz */
#endif



/* make sure we have the UART defines: */
// #include "usbportability.h"

#ifndef uchar
#   define  uchar   unsigned char
#endif

#ifndef DEBUG_LEVEL
#   define  DEBUG_LEVEL 0
#endif

/* ------------------------------------------------------------------------- */

#if DEBUG_LEVEL > 0
#   define  DBG1(prefix, data, len) odDebug(prefix, data, len)
#   define  DEBUGF(fmt,args...) odPrintf(fmt, ## args)
#   define  DPUTCH(chr) odPutCh(chr)
#else
#   define  DBG1(prefix, data, len)
#   define  DEBUGF(fmt,args...)
#   define  DPUTCH(chr)
#endif

#if DEBUG_LEVEL > 1
#   define  DBG2(prefix, data, len) odDebug(prefix, data, len)
#else
#   define  DBG2(prefix, data, len)
#endif

/* ------------------------------------------------------------------------- */

#if DEBUG_LEVEL > 0

#ifdef __cplusplus
extern "C" {
#endif

extern void odDebug(uchar prefix, uchar *data, uchar len);
extern void odPrintf(const char *fmt, ...);
extern void odPutCh(uchar chr);
extern void odHexDump( const char *prefix, const uint8_t *data, uint8_t len );

#ifdef __cplusplus
 } /* extern "C" */


class SerialDebug
{
    public:
        static void print(unsigned int x) { odPrintf("%u", x); }
        static void print(int x) { odPrintf("%d", x); }
        static void print(const char *x) { odPrintf("%s", x); }
        static void print(unsigned int x, const char *f) { odPrintf(f, x); }
        static void print(int x, const char *f) { odPrintf(f, x); }

        static void println(unsigned int x) { odPrintf("%u\n", x); }
        static void println(int x) { odPrintf("%d\n", x); }
        static void println(const char *x) { odPrintf("%s\n", x); }
        static void println(unsigned int x, const char *f) { odPrintf(f, x); odPutCh('\n'); }
        static void println(int x, const char *f) { odPrintf(f, x); odPutCh('\n'); }
};

#endif

/* Try to find our control registers; ATMEL likes to rename these */

#ifdef __AVR__

#if defined UBRR
#   define  ODDBG_UBRR  UBRR
#elif defined UBRRL
#   define  ODDBG_UBRR  UBRRL
#elif defined UBRR0
#   define  ODDBG_UBRR  UBRR0
#elif defined UBRR0L
#   define  ODDBG_UBRR  UBRR0L
#elif defined UBRR1L
#   define  ODDBG_UBRR  UBRR1L
#endif

#if defined UCR
#   define  ODDBG_UCR   UCR
#elif defined UCSRB
#   define  ODDBG_UCR   UCSRB
#elif defined UCSR0B
#   define  ODDBG_UCR   UCSR0B
#elif defined UCSR1B
#   define  ODDBG_UCR   UCSR1B
#endif

#if defined TXEN
#   define  ODDBG_TXEN  TXEN
#elif defined TXEN0
#   define  ODDBG_TXEN  TXEN0
#elif defined TXEN1
#   define  ODDBG_TXEN  TXEN1
#endif

#if defined USR
#   define  ODDBG_USR   USR
#elif defined UCSRA
#   define  ODDBG_USR   UCSRA
#elif defined UCSR0A
#   define  ODDBG_USR   UCSR0A
#elif defined UCSR1A
#   define  ODDBG_USR   UCSR1A
#endif

#if defined UDRE
#   define  ODDBG_UDRE  UDRE
#elif defined UDRE0
#   define  ODDBG_UDRE  UDRE0
#elif defined UDRE1
#   define  ODDBG_UDRE  UDRE1
#endif

#if defined UDR
#   define  ODDBG_UDR   UDR
#elif defined UDR0
#   define  ODDBG_UDR   UDR0
#elif defined UDR1
#   define  ODDBG_UDR   UDR1
#endif

static inline void  odDebugInit(void)
{
    ODDBG_UCR |= (1<<ODDBG_TXEN);
    ODDBG_UBRR = F_CPU / (57600 * 16L) - 1;
}
#else /* __AVR__ */



#endif

#else
#   define odDebugInit()
#endif

/* ------------------------------------------------------------------------- */

#endif /* __oddebug_h_included__ */
