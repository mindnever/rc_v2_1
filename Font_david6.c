#include <stddef.h>
#include <gfx/gfx.h>

static const FontChar david6_20 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  0, /* width */ 
  0, /* height */ 
  { /* Bitmap Data */
  }
};

static const FontChar david6_21 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x00,		/*          */
    0x80		/* #        */
  }
};

static const FontChar david6_22 PROGMEM =
{
  0, /* offsetX */ 
  6, /* offsetY */ 
  3, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0xa0		/* # #      */
  }
};

static const FontChar david6_23 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x50,		/*  # #     */
    0x50		/*  # #     */
  }
};

static const FontChar david6_24 PROGMEM =
{
  0, /* offsetX */ 
  -1, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x70,		/*  ###     */
    0xa8,		/* # # #    */
    0xa0,		/* # #      */
    0x60,		/*  ##      */
    0x30,		/*   ##     */
    0x28,		/*   # #    */
    0xa8,		/* # # #    */
    0x70,		/*  ###     */
    0x20		/*   #      */
  }
};

static const FontChar david6_25 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  7, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x48,		/*  #  #    */
    0xa8,		/* # # #    */
    0xa8,		/* # # #    */
    0x50,		/*  # #     */
    0x14,		/*    # #   */
    0x2a,		/*   # # #  */
    0x2a,		/*   # # #  */
    0x24		/*   #  #   */
  }
};

static const FontChar david6_26 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  7, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x6c,		/*  ## ##   */
    0x90,		/* #  #     */
    0x92,		/* #  #  #  */
    0x6c		/*  ## ##   */
  }
};

static const FontChar david6_27 PROGMEM =
{
  0, /* offsetX */ 
  6, /* offsetY */ 
  1, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_28 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x40		/*  #       */
  }
};

static const FontChar david6_29 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_2a PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  5, /* width */ 
  4, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0xf8,		/* #####    */
    0x20,		/*   #      */
    0x50		/*  # #     */
  }
};

static const FontChar david6_2b PROGMEM =
{
  0, /* offsetX */ 
  1, /* offsetY */ 
  5, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0xf8,		/* #####    */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_2c PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  3, /* height */ 
  { /* Bitmap Data */
    0xc0,		/* ##       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_2d PROGMEM =
{
  0, /* offsetX */ 
  2, /* offsetY */ 
  3, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0xe0		/* ###      */
  }
};

static const FontChar david6_2e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0x80		/* #        */
  }
};

static const FontChar david6_2f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_30 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_31 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xc0,		/* ##       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_32 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_33 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x60,		/*  ##      */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_34 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x30,		/*   ##     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x90,		/* #  #     */
    0xf8,		/* #####    */
    0x10,		/*    #     */
    0x10		/*    #     */
  }
};

static const FontChar david6_35 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xe0,		/* ###      */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0xe0		/* ###      */
  }
};

static const FontChar david6_36 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x80,		/* #        */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_37 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_38 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_39 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70,		/*  ###     */
    0x10,		/*    #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_3a PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0x80		/* #        */
  }
};

static const FontChar david6_3b PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x00,		/*          */
    0x00,		/*          */
    0x00,		/*          */
    0xc0,		/* ##       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_3c PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x20		/*   #      */
  }
};

static const FontChar david6_3d PROGMEM =
{
  0, /* offsetX */ 
  2, /* offsetY */ 
  4, /* width */ 
  3, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x00,		/*          */
    0xf0		/* ####     */
  }
};

static const FontChar david6_3e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_3f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x00,		/*          */
    0x40		/*  #       */
  }
};

static const FontChar david6_40 PROGMEM =
{
  0, /* offsetX */ 
  -1, /* offsetY */ 
  8, /* width */ 
  9, /* height */ 
  { /* Bitmap Data */
    0x3c,		/*   ####   */
    0x42,		/*  #    #  */
    0x99,		/* #  ##  # */
    0xa5,		/* # #  # # */
    0x9d,		/* #  ### # */
    0xa5,		/* # #  # # */
    0x9e,		/* #  ####  */
    0x40,		/*  #       */
    0x3e		/*   #####  */
  }
};

static const FontChar david6_41 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_42 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0		/* ###      */
  }
};

static const FontChar david6_43 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x48,		/*  #  #    */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x48,		/*  #  #    */
    0x30		/*   ##     */
  }
};

static const FontChar david6_44 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x90,		/* #  #     */
    0xe0		/* ###      */
  }
};

static const FontChar david6_45 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_46 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_47 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x48,		/*  #  #    */
    0x80,		/* #        */
    0x80,		/* #        */
    0x98,		/* #  ##    */
    0x88,		/* #   #    */
    0x48,		/*  #  #    */
    0x30		/*   ##     */
  }
};

static const FontChar david6_48 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90		/* #  #     */
  }
};

static const FontChar david6_49 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_4a PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40		/*  #       */
  }
};

static const FontChar david6_4b PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xc0,		/* ##       */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x90,		/* #  #     */
    0x90		/* #  #     */
  }
};

static const FontChar david6_4c PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_4d PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0xd8,		/* ## ##    */
    0xd8,		/* ## ##    */
    0xa8,		/* # # #    */
    0xa8,		/* # # #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_4e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xc8,		/* ##  #    */
    0xa8,		/* # # #    */
    0x98,		/* #  ##    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_4f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_50 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0,		/* ###      */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_51 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xa8,		/* # # #    */
    0x98,		/* #  ##    */
    0x78		/*  ####    */
  }
};

static const FontChar david6_52 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0,		/* ###      */
    0xc0,		/* ##       */
    0xa0,		/* # #      */
    0x90		/* #  #     */
  }
};

static const FontChar david6_53 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x10,		/*    #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_54 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_55 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_56 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_57 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  9, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,0x80,		/* #       #        */
    0x80,0x80,		/* #       #        */
    0x80,0x80,		/* #       #        */
    0x49,0x00,		/*  #  #  #         */
    0x49,0x00,		/*  #  #  #         */
    0x55,0x00,		/*  # # # #         */
    0x22,0x00,		/*   #   #          */
    0x22,0x00		/*   #   #          */
  }
};

static const FontChar david6_58 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_59 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_5a PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_5b PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0		/* ##       */
  }
};

static const FontChar david6_5c PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_5d PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0xc0,		/* ##       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0xc0		/* ##       */
  }
};

static const FontChar david6_5e PROGMEM =
{
  0, /* offsetX */ 
  5, /* offsetY */ 
  5, /* width */ 
  3, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x88		/* #   #    */
  }
};

static const FontChar david6_5f PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  5, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0xf8		/* #####    */
  }
};

static const FontChar david6_60 PROGMEM =
{
  0, /* offsetX */ 
  6, /* offsetY */ 
  2, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40		/*  #       */
  }
};

static const FontChar david6_61 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_62 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0		/* ###      */
  }
};

static const FontChar david6_63 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x80,		/* #        */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_64 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x10,		/*    #     */
    0x70,		/*  ###     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_65 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x70		/*  ###     */
  }
};

static const FontChar david6_66 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0xe0,		/* ###      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_67 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x70,		/*  ###     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70,		/*  ###     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_68 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90		/* #  #     */
  }
};

static const FontChar david6_69 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x00,		/*          */
    0x00,		/*          */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_6a PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x00,		/*          */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_6b PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x90,		/* #  #     */
    0xa0,		/* # #      */
    0xc0,		/* ##       */
    0xa0,		/* # #      */
    0x90		/* #  #     */
  }
};

static const FontChar david6_6c PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  1, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_6d PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  7, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xec,		/* ### ##   */
    0x92,		/* #  #  #  */
    0x92,		/* #  #  #  */
    0x92,		/* #  #  #  */
    0x92		/* #  #  #  */
  }
};

static const FontChar david6_6e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90		/* #  #     */
  }
};

static const FontChar david6_6f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_70 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xe0,		/* ###      */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_71 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x70,		/*  ###     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70,		/*  ###     */
    0x10,		/*    #     */
    0x10		/*    #     */
  }
};

static const FontChar david6_72 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_73 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0xc0		/* ##       */
  }
};

static const FontChar david6_74 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0xe0,		/* ###      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_75 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_76 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x20		/*   #      */
  }
};

static const FontChar david6_77 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x88,		/* #   #    */
    0xa8,		/* # # #    */
    0xa8,		/* # # #    */
    0x50,		/*  # #     */
    0x50		/*  # #     */
  }
};

static const FontChar david6_78 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0xa0		/* # #      */
  }
};

static const FontChar david6_79 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  3, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_7a PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xf0,		/* ####     */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_7b PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  3, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x20		/*   #      */
  }
};

static const FontChar david6_7c PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  1, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_7d PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  3, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_7e PROGMEM =
{
  0, /* offsetX */ 
  1, /* offsetY */ 
  4, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0		/* # ##     */
  }
};

static const FontChar david6_7f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_80 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x3c,		/*   ####   */
    0x40,		/*  #       */
    0xf8,		/* #####    */
    0x40,		/*  #       */
    0xf0,		/* ####     */
    0x40,		/*  #       */
    0x44,		/*  #   #   */
    0x38		/*   ###    */
  }
};

static const FontChar david6_81 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_8d PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_8e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_8f PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_90 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_9d PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_9e PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_a0 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  0, /* width */ 
  0, /* height */ 
  { /* Bitmap Data */
  }
};

static const FontChar david6_a1 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  1, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x00,		/*          */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_a2 PROGMEM =
{
  0, /* offsetX */ 
  -1, /* offsetY */ 
  5, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x70,		/*  ###     */
    0xa8,		/* # # #    */
    0xa0,		/* # #      */
    0xa8,		/* # # #    */
    0x70,		/*  ###     */
    0x20		/*   #      */
  }
};

static const FontChar david6_a3 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0xe0,		/* ###      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0xd0,		/* ## #     */
    0xb0		/* # ##     */
  }
};

static const FontChar david6_a4 PROGMEM =
{
  0, /* offsetX */ 
  1, /* offsetY */ 
  4, /* width */ 
  6, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60,		/*  ##      */
    0x90		/* #  #     */
  }
};

static const FontChar david6_a5 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  7, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xee,		/* ### ###  */
    0x44,		/*  #   #   */
    0x28,		/*   # #    */
    0x7c,		/*  #####   */
    0x10,		/*    #     */
    0x7c,		/*  #####   */
    0x10,		/*    #     */
    0x38		/*   ###    */
  }
};

static const FontChar david6_a6 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  1, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x00,		/*          */
    0x00,		/*          */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_a7 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_a8 PROGMEM =
{
  0, /* offsetX */ 
  6, /* offsetY */ 
  3, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0xa0		/* # #      */
  }
};

static const FontChar david6_a9 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  8, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x3c,		/*   ####   */
    0x42,		/*  #    #  */
    0x9d,		/* #  ### # */
    0xa1,		/* # #    # */
    0xa1,		/* # #    # */
    0x9d,		/* #  ### # */
    0x42,		/*  #    #  */
    0x3c		/*   ####   */
  }
};

static const FontChar david6_aa PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x60,		/*  ##      */
    0xa0,		/* # #      */
    0xe0		/* ###      */
  }
};

static const FontChar david6_ab PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x24,		/*   #  #   */
    0x48,		/*  #  #    */
    0x90,		/* #  #     */
    0x48,		/*  #  #    */
    0x24		/*   #  #   */
  }
};

static const FontChar david6_ac PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  5, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x08		/*     #    */
  }
};

static const FontChar david6_ad PROGMEM =
{
  0, /* offsetX */ 
  2, /* offsetY */ 
  2, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0xc0		/* ##       */
  }
};

static const FontChar david6_ae PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  8, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x3c,		/*   ####   */
    0x42,		/*  #    #  */
    0xb9,		/* # ###  # */
    0xa5,		/* # #  # # */
    0xb9,		/* # ###  # */
    0xa5,		/* # #  # # */
    0x42,		/*  #    #  */
    0x3c		/*   ####   */
  }
};

static const FontChar david6_af PROGMEM =
{
  0, /* offsetX */ 
  8, /* offsetY */ 
  5, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0xf8		/* #####    */
  }
};

static const FontChar david6_b0 PROGMEM =
{
  0, /* offsetX */ 
  5, /* offsetY */ 
  3, /* width */ 
  3, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x40		/*  #       */
  }
};

static const FontChar david6_b1 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0xe0,		/* ###      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x00,		/*          */
    0xe0		/* ###      */
  }
};

static const FontChar david6_b2 PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0xe0		/* ###      */
  }
};

static const FontChar david6_b3 PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xe0,		/* ###      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0xc0		/* ##       */
  }
};

static const FontChar david6_b4 PROGMEM =
{
  0, /* offsetX */ 
  6, /* offsetY */ 
  2, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_b5 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  5, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0xf8,		/* #####    */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_b6 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x78,		/*  ####    */
    0xd0,		/* ## #     */
    0xd0,		/* ## #     */
    0xd0,		/* ## #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50		/*  # #     */
  }
};

static const FontChar david6_b7 PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  1, /* width */ 
  1, /* height */ 
  { /* Bitmap Data */
    0x80		/* #        */
  }
};

static const FontChar david6_b8 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  2, /* width */ 
  2, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xc0		/* ##       */
  }
};

static const FontChar david6_b9 PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  2, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xc0,		/* ##       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_ba PROGMEM =
{
  0, /* offsetX */ 
  3, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40		/*  #       */
  }
};

static const FontChar david6_bb PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x90,		/* #  #     */
    0x48,		/*  #  #    */
    0x24,		/*   #  #   */
    0x48,		/*  #  #    */
    0x90		/* #  #     */
  }
};

static const FontChar david6_bc PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_bd PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_be PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_bf PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_c0 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c1 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c2 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c3 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x68,		/*  ## #    */
    0x58,		/*  # ##    */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c4 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c5 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_c6 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  8, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x1f,		/*    ##### */
    0x28,		/*   # #    */
    0x28,		/*   # #    */
    0x4c,		/*  #  ##   */
    0x48,		/*  #  #    */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x8f		/* #   #### */
  }
};

static const FontChar david6_c7 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x48,		/*  #  #    */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x48,		/*  #  #    */
    0x30,		/*   ##     */
    0x10,		/*    #     */
    0x30		/*   ##     */
  }
};

static const FontChar david6_c8 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_c9 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_ca PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_cb PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x80,		/* #        */
    0xc0,		/* ##       */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0xf0		/* ####     */
  }
};

static const FontChar david6_cc PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_cd PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x00,		/*          */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_ce PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_cf PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_d0 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x70,		/*  ###     */
    0x48,		/*  #  #    */
    0x44,		/*  #   #   */
    0xe4,		/* ###  #   */
    0x44,		/*  #   #   */
    0x44,		/*  #   #   */
    0x48,		/*  #  #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d1 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0,		/* # ##     */
    0x00,		/*          */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xc8,		/* ##  #    */
    0xa8,		/* # # #    */
    0x98,		/* #  ##    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88		/* #   #    */
  }
};

static const FontChar david6_d2 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d3 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d4 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d5 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0,		/* # ##     */
    0x00,		/*          */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d6 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x70,		/*  ###     */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x70		/*  ###     */
  }
};

static const FontChar david6_d7 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0xa0		/* # #      */
  }
};

static const FontChar david6_d8 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x78,		/*  ####    */
    0x98,		/* #  ##    */
    0x98,		/* #  ##    */
    0xa8,		/* # # #    */
    0xa8,		/* # # #    */
    0xc8,		/* ##  #    */
    0xc8,		/* ##  #    */
    0xf0		/* ####     */
  }
};

static const FontChar david6_d9 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_da PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_db PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_dc PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_dd PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  11, /* height */ 
  { /* Bitmap Data */
    0x10,		/*    #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x50,		/*  # #     */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20,		/*   #      */
    0x20		/*   #      */
  }
};

static const FontChar david6_de PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_df PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x30,		/*   ##     */
    0x48,		/*  #  #    */
    0x48,		/*  #  #    */
    0x50,		/*  # #     */
    0x48,		/*  #  #    */
    0x48,		/*  #  #    */
    0x48,		/*  #  #    */
    0xd0		/* ## #     */
  }
};

static const FontChar david6_e0 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e1 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e2 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e3 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0,		/* # ##     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e4 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e5 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  9, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x20,		/*   #      */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e6 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  7, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x6c,		/*  ## ##   */
    0x92,		/* #  #  #  */
    0x9e,		/* #  ####  */
    0x90,		/* #  #     */
    0x7e		/*  ######  */
  }
};

static const FontChar david6_e7 PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x80,		/* #        */
    0x90,		/* #  #     */
    0x60,		/*  ##      */
    0x20,		/*   #      */
    0x60		/*  ##      */
  }
};

static const FontChar david6_e8 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x70		/*  ###     */
  }
};

static const FontChar david6_e9 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x70		/*  ###     */
  }
};

static const FontChar david6_ea PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x70		/*  ###     */
  }
};

static const FontChar david6_eb PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0xf0,		/* ####     */
    0x80,		/* #        */
    0x70		/*  ###     */
  }
};

static const FontChar david6_ec PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x80,		/* #        */
    0x40,		/*  #       */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_ed PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  2, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x80,		/* #        */
    0x00,		/*          */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80,		/* #        */
    0x80		/* #        */
  }
};

static const FontChar david6_ee PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_ef PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x40		/*  #       */
  }
};

static const FontChar david6_f0 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f1 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0,		/* # ##     */
    0x00,		/*          */
    0xe0,		/* ###      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90		/* #  #     */
  }
};

static const FontChar david6_f2 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f3 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f4 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f5 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xd0,		/* ## #     */
    0xb0,		/* # ##     */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f6 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x00,		/*          */
    0x60,		/*  ##      */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x60		/*  ##      */
  }
};

static const FontChar david6_f7 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  3, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x00,		/*          */
    0xe0,		/* ###      */
    0x00,		/*          */
    0x40		/*  #       */
  }
};

static const FontChar david6_f8 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  6, /* width */ 
  5, /* height */ 
  { /* Bitmap Data */
    0x3c,		/*   ####   */
    0x58,		/*  # ##    */
    0x58,		/*  # ##    */
    0x68,		/*  ## #    */
    0xf0		/* ####     */
  }
};

static const FontChar david6_f9 PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x40,		/*  #       */
    0x20,		/*   #      */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_fa PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_fb PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_fc PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  4, /* width */ 
  7, /* height */ 
  { /* Bitmap Data */
    0x50,		/*  # #     */
    0x00,		/*          */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x90,		/* #  #     */
    0x70		/*  ###     */
  }
};

static const FontChar david6_fd PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  3, /* width */ 
  10, /* height */ 
  { /* Bitmap Data */
    0x20,		/*   #      */
    0x40,		/*  #       */
    0x00,		/*          */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};

static const FontChar david6_fe PROGMEM =
{
  0, /* offsetX */ 
  0, /* offsetY */ 
  5, /* width */ 
  8, /* height */ 
  { /* Bitmap Data */
    0xf8,		/* #####    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0x88,		/* #   #    */
    0xf8		/* #####    */
  }
};

static const FontChar david6_ff PROGMEM =
{
  0, /* offsetX */ 
  -2, /* offsetY */ 
  3, /* width */ 
  9, /* height */ 
  { /* Bitmap Data */
    0xa0,		/* # #      */
    0x00,		/*          */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0xa0,		/* # #      */
    0x40,		/*  #       */
    0x40,		/*  #       */
    0x80		/* #        */
  }
};



const Font david6 PROGMEM = 
{
  32, /* minChar */
  255, /* maxChar */
  9, /* maxWidth */
  10, /* maxHeight */

  { /* FontChar index */
    &david6_20,
    &david6_21,
    &david6_22,
    &david6_23,
    &david6_24,
    &david6_25,
    &david6_26,
    &david6_27,
    &david6_28,
    &david6_29,
    &david6_2a,
    &david6_2b,
    &david6_2c,
    &david6_2d,
    &david6_2e,
    &david6_2f,
    &david6_30,
    &david6_31,
    &david6_32,
    &david6_33,
    &david6_34,
    &david6_35,
    &david6_36,
    &david6_37,
    &david6_38,
    &david6_39,
    &david6_3a,
    &david6_3b,
    &david6_3c,
    &david6_3d,
    &david6_3e,
    &david6_3f,
    &david6_40,
    &david6_41,
    &david6_42,
    &david6_43,
    &david6_44,
    &david6_45,
    &david6_46,
    &david6_47,
    &david6_48,
    &david6_49,
    &david6_4a,
    &david6_4b,
    &david6_4c,
    &david6_4d,
    &david6_4e,
    &david6_4f,
    &david6_50,
    &david6_51,
    &david6_52,
    &david6_53,
    &david6_54,
    &david6_55,
    &david6_56,
    &david6_57,
    &david6_58,
    &david6_59,
    &david6_5a,
    &david6_5b,
    &david6_5c,
    &david6_5d,
    &david6_5e,
    &david6_5f,
    &david6_60,
    &david6_61,
    &david6_62,
    &david6_63,
    &david6_64,
    &david6_65,
    &david6_66,
    &david6_67,
    &david6_68,
    &david6_69,
    &david6_6a,
    &david6_6b,
    &david6_6c,
    &david6_6d,
    &david6_6e,
    &david6_6f,
    &david6_70,
    &david6_71,
    &david6_72,
    &david6_73,
    &david6_74,
    &david6_75,
    &david6_76,
    &david6_77,
    &david6_78,
    &david6_79,
    &david6_7a,
    &david6_7b,
    &david6_7c,
    &david6_7d,
    &david6_7e,
    &david6_7f,
    &david6_80,
    &david6_81,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &david6_8d,
    &david6_8e,
    &david6_8f,
    &david6_90,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &david6_9d,
    &david6_9e,
    NULL,
    &david6_a0,
    &david6_a1,
    &david6_a2,
    &david6_a3,
    &david6_a4,
    &david6_a5,
    &david6_a6,
    &david6_a7,
    &david6_a8,
    &david6_a9,
    &david6_aa,
    &david6_ab,
    &david6_ac,
    &david6_ad,
    &david6_ae,
    &david6_af,
    &david6_b0,
    &david6_b1,
    &david6_b2,
    &david6_b3,
    &david6_b4,
    &david6_b5,
    &david6_b6,
    &david6_b7,
    &david6_b8,
    &david6_b9,
    &david6_ba,
    &david6_bb,
    &david6_bc,
    &david6_bd,
    &david6_be,
    &david6_bf,
    &david6_c0,
    &david6_c1,
    &david6_c2,
    &david6_c3,
    &david6_c4,
    &david6_c5,
    &david6_c6,
    &david6_c7,
    &david6_c8,
    &david6_c9,
    &david6_ca,
    &david6_cb,
    &david6_cc,
    &david6_cd,
    &david6_ce,
    &david6_cf,
    &david6_d0,
    &david6_d1,
    &david6_d2,
    &david6_d3,
    &david6_d4,
    &david6_d5,
    &david6_d6,
    &david6_d7,
    &david6_d8,
    &david6_d9,
    &david6_da,
    &david6_db,
    &david6_dc,
    &david6_dd,
    &david6_de,
    &david6_df,
    &david6_e0,
    &david6_e1,
    &david6_e2,
    &david6_e3,
    &david6_e4,
    &david6_e5,
    &david6_e6,
    &david6_e7,
    &david6_e8,
    &david6_e9,
    &david6_ea,
    &david6_eb,
    &david6_ec,
    &david6_ed,
    &david6_ee,
    &david6_ef,
    &david6_f0,
    &david6_f1,
    &david6_f2,
    &david6_f3,
    &david6_f4,
    &david6_f5,
    &david6_f6,
    &david6_f7,
    &david6_f8,
    &david6_f9,
    &david6_fa,
    &david6_fb,
    &david6_fc,
    &david6_fd,
    &david6_fe,
    &david6_ff,
  }
};
