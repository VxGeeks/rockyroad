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
**  Filename :	IC_Init.c
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
//
//
//
/****************************°üº¬Í·ÎÄŒþ***************************/

#include "IC.h"
#include "IC_Init.h"
#include "Delay.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>
//
//
#define Interface_SPI   //¶šÒåÍšÐÅ·œÊœœÓ¿ÚÎª IIC
//
//

#ifdef  Interface_8080

/**********************************************
//
//ÐŽÃüÁîº¯Êý

**********************************************/
//
//

void Write_Command(uchar command)
{
   CS = low;
   DC = low;
   WR = low;
   _nop_();_nop_();
   P0 = command;
   WR = high;
   _nop_();_nop_();
   CS = high;
}

//
//
//
/**********************************************
//
//ÐŽÊýŸÝº¯Êý
//
**********************************************/
//
//
void Write_Data(uchar date)
{
   CS = low;
   DC = high;
   WR = low;
   _nop_();_nop_();
   P0 = date;
   WR = high;
   _nop_();_nop_();
   CS = high;
}

#endif

#ifdef  Interface_IIC

/**********************************************
//
//IICÍšÐÅ¿ªÊŒº¯Êý
//
**********************************************/

void IC_IIC_Start()
{
   SDA = high;
   SCL = high;
   _nop_();
   SDA = low;
   _nop_();_nop_();
   SCL = low;
}

/**********************************************
//
//IICÍšÐÅÍ£Ö¹º¯Êý
//
**********************************************/

void IC_IIC_Stop()
{
   SDA = low;
   _nop_();
   SCL = high;
   _nop_();_nop_();
   SDA = high;
}

/**********************************************
//
//ÏòIICÐŽÊýŸÝº¯Êý
//·µ»ØÖµÎªacknowledgementÎ»ÐÅºÅ
//
**********************************************/

bit Write_IIC_Data(uchar Data)
{
	unsigned char i;
	bit Ack_Bit;                    //ÓŠŽðÐÅºÅ
	for(i = 0; i < 8; i++)		
	{
		SDA = (bit)(Data & 0x80);
		_nop_();
		SCL = high;
		_nop_();_nop_();
		SCL = low;
		Data = _crol_(Data,1);
	}
	SDA = high;		                //ÊÍ·ÅIIC SDA×ÜÏßÎªÖ÷Æ÷ŒþœÓÊÕŽÓÆ÷Œþ²úÉúÓŠŽðÐÅºÅ	
	_nop_();_nop_();
	SCL = high;                     //µÚ9žöÊ±ÖÓÖÜÆÚ
	_nop_();_nop_();
	Ack_Bit = SDA;		            //¶ÁÈ¡ÓŠŽðÐÅºÅ
	SCL = low;
	return Ack_Bit;		
}

/**********************************************
//
//ÐŽÃüÁîº¯Êý

**********************************************/
//
//

void Write_Command(uchar command)
{
   IC_IIC_Start();
   Write_IIC_Data(Slave_Address);                //Salve Adress
   Write_IIC_Data(OP_Command);                   //ÐŽÃüÁî
   Write_IIC_Data(command); 
   IC_IIC_Stop();
}

/**********************************************
//
//ÐŽÊýŸÝº¯Êý
//
**********************************************/
//
//

void Write_Data(uchar date)
{
   IC_IIC_Start();
   Write_IIC_Data(Slave_Address);                //Salve Adress
   Write_IIC_Data(OP_Data);                      //ÐŽÊýŸÝ
   Write_IIC_Data(date);
   IC_IIC_Stop();
}


#endif

#ifdef  Interface_SPI

/**********************************************
//
// Write a Command

**********************************************/
//
//

void Write_Command(uchar command)
{
   uchar i,value;
   value = command;
//   CS = low;
   //DC = low;
   digitalWrite(DC, LOW);

   /*
   for(i=0;i<8;i++)
   {
     SCLK = low;
	 _nop_(); _nop_();
     if(value & 0x80) SDIN = high;
	 else  SDIN = low;
	 SCLK = high;
	 _nop_(); _nop_();
	value =  _crol_(value, 1);
   }
   */
   wiringPiSPIDataRW(0,&value,sizeof(value));

//   CS = high;
}

//
//

/**********************************************
//
// Write a byte of data

**********************************************/
//
//

void Write_Data(uchar data)
{
   uchar i,value;
   value = data;
//   CS = low;
   //DC = high;
   digitalWrite(DC,HIGH);

   /*
   for(i=0;i<8;i++)
   {
     SCLK = low;
	 _nop_(); _nop_();
     if(value & 0x80) SDIN = high;
	 else  SDIN = low;
	 SCLK = high;
	 _nop_(); _nop_();
	value =  _crol_(value, 1);
   }
    */

   wiringPiSPIDataRW(0,&value,sizeof(value));
//   CS = high;
}

#endif
/******************************************************
//
// Reset OLED Driver
//
******************************************************/
//
//

void Reset_IC()
{
   Delay_Ms(10);
//   LED_Work = low;
   //RES = low;
   digitalWrite(RES, LOW);
   Delay_Ms(100);
   //RES = high;
   digitalWrite(RES, HIGH);
   Delay_Ms(100);
//   VCC_Change = high;
}

/******************************************************
//
// Initialize OLED Driver
//
******************************************************/
//
//

void Init_IC(void)
{
   Write_Command(0xAE);     //Set Display Off 

   Write_Command(0xd5);     //display divide ratio/osc. freq. mode	
   Write_Command(0x91);     //
 
   Write_Command(0xA8);     //multiplex ration mode:63 
   Write_Command(0x1F);

   Write_Command(0xD3);     //Set Display Offset   
   Write_Command(0x10);
   
   Write_Command(0x40);     //Set Display Start Line 
   
   Write_Command(0xAD);     //DC-DC Control Mode Set 
   Write_Command(0x8b);     //DC-DC ON/OFF Mode Set 

   Write_Command(0x33);     //Set Pump voltage value 

   Write_Command(0xA1);     //Segment Remap	 

   Write_Command(0xC8);     //Sst COM Output Scan Direction	

   Write_Command(0xDA);     //common pads hardware: alternative	
   Write_Command(0x12);

   Write_Command(0x81);     //contrast control 
   Write_Command(0xaf);		//

   Write_Command(0xD9);	    //set pre-charge period	  
   Write_Command(0x1f);

   Write_Command(0xDB);     //VCOM deselect level mode 
   Write_Command(0x25);	    //

   Write_Command(0xA4);     //Set Entire Display On/Off	

   Write_Command(0xA6);     //Set Normal Display 

   Write_Command(0xAF);     //Set Display On 
}


