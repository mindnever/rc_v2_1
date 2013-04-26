#include <stddef.h>
#include <gfx/gfx.h>

static const FontChar digits15_2d PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x00,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  }
};

static const FontChar digits15_2e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0x03,		/* ##       */
    0x03		/* ##       */
  }
};

static const FontChar digits15_30 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_31 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x0e,		/*  ###     */
    0x0e,		/*  ###     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x1e,		/*  ####    */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_32 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x38,		/*    ###   */
    0x1c,		/*   ###    */
    0x0e,		/*  ###     */
    0x07,		/* ###      */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x3f,		/* ######   */
    0x3f		/* ######   */
  }
};

static const FontChar digits15_33 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x1c,		/*   ###    */
    0x3c,		/*   ####   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_34 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x3f,		/* ######   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30		/*     ##   */
  }
};

static const FontChar digits15_35 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x3f,		/* ######   */
    0x3f,		/* ######   */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x0f,		/* ####     */
    0x1f,		/* #####    */
    0x38,		/*    ###   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x3b,		/* ## ###   */
    0x1f,		/* #####    */
    0x0e		/*  ###     */
  }
};

static const FontChar digits15_36 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x1f,		/* #####    */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x1f,		/* #####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_37 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x3f,		/* ######   */
    0x3f,		/* ######   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x38,		/*    ###   */
    0x18,		/*    ##    */
    0x18,		/*    ##    */
    0x18,		/*    ##    */
    0x1c,		/*   ###    */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x0c,		/*   ##     */
    0x06,		/*  ##      */
    0x06,		/*  ##      */
    0x06		/*  ##      */
  }
};

static const FontChar digits15_38 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x1e,		/*  ####    */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_39 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  15, /* height */ 
  { /* Bitmap Data */
    0x1e,		/*  ####    */
    0x3f,		/* ######   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x33,		/* ##  ##   */
    0x3f,		/* ######   */
    0x3e,		/*  #####   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x30,		/*     ##   */
    0x3e,		/*  #####   */
    0x1e		/*  ####    */
  }
};

static const FontChar digits15_40 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x03,		/* ##       */
    0x03,		/* ##       */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,		/* ##       */
    0x03		/* ##       */
  }
};




const Font digits15c PROGMEM =
{
  45, /* minChar */
  58, /* maxChar */
  6, /* maxWidth */
  15, /* maxHeight */
  
  { /* FontChar index */
    &digits15_2d,
    &digits15_2e,
    NULL,
    &digits15_30,
    &digits15_31,
    &digits15_32,
    &digits15_33,
    &digits15_34,
    &digits15_35,
    &digits15_36,
    &digits15_37,
    &digits15_38,
    &digits15_39,
    &digits15_40,
  }
};
