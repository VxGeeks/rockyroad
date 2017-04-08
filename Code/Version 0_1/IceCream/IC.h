/**
---------------------------------------------------------------------
**
**  This device driver was created by 
**  8-Bit Single-Chip Microcontrollers
**
**  Copyright(C) visionox display Corporation 2002 - 2009
**  All rights reserved by Kunshan visionox display Corporation.
**
**  This program should be used on your own responsibility.
**
**  Filename :	IC.h
**  Abstract :	This file implements device driver for define SH1106 IC Pin function.
**
**  Device :	STC89LE516RD
**
**  Compiler :	KEIL uVision2 
**
**  Module:  M01031
**
**  Dot Matrix: 128*32
**
**  Display Color: White
**
**  Driver IC: SH1106G
**
**  Edit : 
**
**  Creation date:	
---------------------------------------------------------------------
**/
//#include "reg52.h"

#ifndef  _IC_
#define  _IC_

//
//
#define high 1
#define low 0 
#define W_Data 0x5C
//
//
//

/*************ICÒýœÅ¹ŠÄÜ¶šÒå***************/


//sbit SCLK = P0^0;      //SPIÊ±ÖÓÐÅºÅ
//sbit SDIN = P0^1;      //SPIÊýŸÝÐÅºÅ


/*sbit SCL = P0^0;      //IICÊ±ÖÓÐÅºÅ
sbit SDA = P0^1;      //IICÊýŸÝÐÅºÅ
*/

//sbit DC=P1^2;
//sbit CS=P1^1;
//sbit RES=P1^0;

#define RES 6
#define DC 5
//#define CS 10

//
//
//sbit Key_Auto = P1^6;
//sbit Key_Manual = P1^7;
//
//
//sbit LED_Work = P1^3;
//sbit LED_Auto = P1^4;
//sbit LED_Manual = P1^5;
//
//
//sbit VCC_Change = P3^4;
//
//
#define STATE_MAX 0xFF
#define STATE_MIN 0x00
#define STATE_55 0x55
#define STATE_AA 0xAA
#define START_PAGE 0xB0
#define PAGE_TOTAL 8
#define START_HIGH_BIT 0x10
#define START_LOW_BIT 0x02
#define FRAME_HIGH_ROW 0x01
#define FRAME_LOW_ROW 0x80

#define MIN 0
#define COLUMN_MAX 128
#define ROW_MAX 32
//
//
#define	Slave_Address 0x78		// Æ÷ŒþµØÖ·
#define	OP_Command 0x00
#define	OP_Data 0x40
//
//
#define Manual 1
#define Auto 0
//
//
/**********************************************/
//
//
typedef unsigned int  uint;
typedef unsigned char  uchar;
typedef unsigned long  ulong;

//
//

#endif
