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
**  Filename :	IC_Init.h
**  Abstract :	This file implements device driver for Initial SH1106 IC function.
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

#ifndef  _IC_Init_

#define  _IC_Init_

//void IC_IIC_Start();
//void IC_IIC_Stop();
//bit Write_IIC_Data(uchar Data);

void Write_Command(uchar command);
void Write_Data(uchar date);
void Reset_IC(void);
void Init_IC(void);

#endif
