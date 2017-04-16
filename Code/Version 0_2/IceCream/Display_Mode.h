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
**  Filename :	Display_Mode.h
**  Abstract :	This file implements device driver for display mode function.
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

#include "IC.h"

#ifndef  _Display_Mode_
#define  _Display_Mode_
//
//
void Clear_Screen();
void All_Screen();
void Row_Show135();
void Row_Show246();
void Row_Show147();
void Row_Show258();
void Row_Show369();
void Column_Show135();
void Column_Show246();
void Column_Show147();
void Column_Show258();
void Column_Show369();
void Frame_Show();
void Chess_Board1();
void Chess_Board2();
void Column_Scan();
void Program_Edit();
void Photo_Show();

uchar ROW[3][4]={
{0x49,0x92,0x24,0x49},
{0x92,0x24,0x49,0x92},
{0x24,0x49,0x92,0x24}
};

//JJH add-ins
void V_pinture();
void Column_Show1();
void Column_Show2();
#endif
