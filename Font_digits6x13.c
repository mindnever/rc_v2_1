#include <stddef.h>
#include "Font.h"

static const FontChar digits6x13_20 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
  }
};

static const FontChar digits6x13_2d PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0xfc,		/* ######   */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_2e PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x30,		/*   ##     */
    0x78,		/*  ####    */
    0x30,		/*   ##     */
    0x00		/*          */
  }
};

static const FontChar digits6x13_30 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x30,		/*   ##     */
    0x78,		/*  ####    */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0x30,		/*   ##     */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_31 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x30,		/*   ##     */
    0x70,		/*  ###     */
    0xf0,		/* ####     */
    0x30,		/*   ##     */
    0x30,		/*   ##     */
    0x30,		/*   ##     */
    0x30,		/*   ##     */
    0x30,		/*   ##     */
    0xfc,		/* ######   */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_32 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x78,		/*  ####    */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0x0c,		/*     ##   */
    0x18,		/*    ##    */
    0x30,		/*   ##     */
    0x60,		/*  ##      */
    0xc0,		/* ##       */
    0xfc,		/* ######   */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_33 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0xfc,		/* ######   */
    0x0c,		/*     ##   */
    0x18,		/*    ##    */
    0x30,		/*   ##     */
    0x78,		/*  ####    */
    0x0c,		/*     ##   */
    0x0c,		/*     ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_34 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x18,		/*    ##    */
    0x18,		/*    ##    */
    0x38,		/*   ###    */
    0x78,		/*  ####    */
    0x58,		/*  # ##    */
    0xd8,		/* ## ##    */
    0xfc,		/* ######   */
    0x18,		/*    ##    */
    0x18,		/*    ##    */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_35 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0xfc,		/* ######   */
    0xc0,		/* ##       */
    0xc0,		/* ##       */
    0xf8,		/* #####    */
    0xec,		/* ### ##   */
    0x0c,		/*     ##   */
    0x0c,		/*     ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_36 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x38,		/*   ###    */
    0x60,		/*  ##      */
    0xc0,		/* ##       */
    0xc0,		/* ##       */
    0xf8,		/* #####    */
    0xec,		/* ### ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_37 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0xfc,		/* ######   */
    0x0c,		/*     ##   */
    0x18,		/*    ##    */
    0x18,		/*    ##    */
    0x30,		/*   ##     */
    0x30,		/*   ##     */
    0x60,		/*  ##      */
    0x60,		/*  ##      */
    0x60,		/*  ##      */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_38 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x78,		/*  ####    */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0x78,		/*  ####    */
    0x00,		/*          */
    0x00		/*          */
  }
};

static const FontChar digits6x13_39 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  6, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0x78,		/*  ####    */
    0xcc,		/* ##  ##   */
    0xcc,		/* ##  ##   */
    0xdc,		/* ## ###   */
    0x7c,		/*  #####   */
    0x0c,		/*     ##   */
    0x0c,		/*     ##   */
    0x18,		/*    ##    */
    0x70,		/*  ###     */
    0x00,		/*          */
    0x00		/*          */
  }
};


static const FontChar digits6x13_40 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  13, /* height */ 
  { /* Bitmap Data */
    0x00,		/*          */
    0x00,		/*          */
    0xc0,		/* ##       */
    0xc0,		/* ##       */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0xc0,		/* ##       */
    0xc0,		/* ##       */
    0x00,		/*          */
    0x00		/*          */
  }
};



const Font digits6x13 PROGMEM = 
{
  44, /* minChar */
  58, /* maxChar */
  6, /* maxWidth */
  13, /* maxHeight */
  { /* FontChar index */
    &digits6x13_20,
    &digits6x13_2d,
    &digits6x13_2e,
    0,
    &digits6x13_30,
    &digits6x13_31,
    &digits6x13_32,
    &digits6x13_33,
    &digits6x13_34,
    &digits6x13_35,
    &digits6x13_36,
    &digits6x13_37,
    &digits6x13_38,
    &digits6x13_39,
    &digits6x13_40,
  }
};
