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
**  Filename :	Display_Mode.c
**  Abstract :	This file implements device driver for Display_Mode function.
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

//#include "Display_Mode.h"
#include "IC.h"
#include "IC_Init.h"
#include "Photo_Show.h"
#include "Delay.h"

//
//

extern uchar ROW[3][4];

/******************************************************
//
//ÇåÆÁÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Clear_Screen()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(STATE_MIN);
     }
   }
}

/******************************************************
//
//È«ÆÁÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void All_Screen()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(STATE_MAX);
     }
   }
}

/******************************************************
//
//žôÐÐ135ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Row_Show135()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(STATE_55);
     }
   }
}

/******************************************************
//
//žôÐÐ246ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Row_Show246()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(STATE_AA);
     }
   }
}
/******************************************************
//
//žôÐÐ147ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Row_Show147()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(ROW[0][page_number]);
     }
   } 
}
/******************************************************
//
//žôÐÐ258ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Row_Show258()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(ROW[1][page_number]);
     }
   }
}

/******************************************************
//
//žôÐÐ369ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Row_Show369()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
     {
        Write_Data(ROW[2][page_number]);
     }
   }
}

/******************************************************
//
//žôÁÐ135ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Column_Show1()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<(COLUMN_MAX/2);column_number++)
     {
        Write_Data(STATE_MAX);
        Write_Data(STATE_MIN);
     }
   }
}

/******************************************************
//
//žôÁÐ246ÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Column_Show2()
{
   uchar page_number,column_number;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     for(column_number=MIN;column_number<(COLUMN_MAX/2);column_number++)
     {
        Write_Data(STATE_MIN);
        Write_Data(STATE_MAX);
     }
   }
}
/******************************************************
//
//±ß¿òÏÔÊŸÄ£Êœ128*36
//
******************************************************/
//
//

void Frame_Show()
{
   uchar page_number,column_number;
   Write_Command(START_PAGE);
   Write_Command(START_HIGH_BIT);
   Write_Command(START_LOW_BIT);
   Write_Data(STATE_MAX);
   for(column_number=MIN;column_number<(COLUMN_MAX-2);column_number++)
   {
      Write_Data(FRAME_HIGH_ROW);
   }
   Write_Data(STATE_MAX);
   for(page_number=MIN+1;page_number<PAGE_TOTAL/2;page_number++)
   {
     Write_Command(START_PAGE+page_number);
     Write_Command(START_HIGH_BIT);
     Write_Command(START_LOW_BIT);
     Write_Data(STATE_MAX);
     for(column_number=MIN;column_number<(COLUMN_MAX-2);column_number++)
     {
        Write_Data(STATE_MIN);
     }
     Write_Data(STATE_MAX);
   }
   Write_Command(START_PAGE+3);
   Write_Command(START_HIGH_BIT);
   Write_Command(START_LOW_BIT);
   Write_Data(STATE_MAX);
   for(column_number=MIN;column_number<(COLUMN_MAX-2);column_number++)
   {
      Write_Data(FRAME_LOW_ROW);
   }
   Write_Data(STATE_MAX);

}

//
//

/******************************************************
//
//ÆåÅÌžñ1
//
******************************************************/
//
//

void Chess_Board1()
{
   uchar page_number,column_number_1,column_number_2,board;
   board=0xFF;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
	  Write_Command(START_PAGE+page_number);
      Write_Command(START_HIGH_BIT);
      Write_Command(START_LOW_BIT);
	  for(column_number_1=MIN;column_number_1<COLUMN_MAX/8;column_number_1++)
	  {
		 for(column_number_2=MIN;column_number_2<COLUMN_MAX/16;column_number_2++)
	     {
	   	    Write_Data(board);
		 }
         board=~board;
	  }
	  board=~board;
   }
}	

/******************************************************
//
//ÆåÅÌžñ2
//
******************************************************/
//
//

void Chess_Board2()
{
   uchar page_number,column_number_1,column_number_2,board;
   board=0x00;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
	  Write_Command(START_PAGE+page_number);
      Write_Command(START_HIGH_BIT);
      Write_Command(START_LOW_BIT);
	  for(column_number_1=MIN;column_number_1<COLUMN_MAX/8;column_number_1++)
	  {
		 for(column_number_2=MIN;column_number_2<COLUMN_MAX/16;column_number_2++)
	     {
	   	    Write_Data(board);
		 }
         board=~board;
	  }
	  board=~board;
   }
}

/******************************************************
//
//ÁÐÉšÃèÏÔÊŸÄ£Êœ
//
******************************************************/
//
//

void Column_Scan()
{
   uchar page_number,column_number_1,column_number_2;
   for(column_number_1=MIN;column_number_1<(COLUMN_MAX/4);column_number_1++)
   {
      for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
      {
         Write_Command(START_PAGE+page_number);
         Write_Command(START_HIGH_BIT);
         Write_Command(START_LOW_BIT);
         for(column_number_2=MIN;column_number_2<COLUMN_MAX;column_number_2++)
         {
		    if((column_number_2==column_number_1)||(column_number_2==column_number_1+(COLUMN_MAX/4))||(column_number_2==column_number_1+(COLUMN_MAX/4*2))||(column_number_2==column_number_1+(COLUMN_MAX/4*3)))
		    Write_Data(STATE_MAX);
		    else Write_Data(STATE_MIN);
		 }
      } 
      Delay_Ms(60);
   }
}


//
//
/******************************************************
//
//³ÌÐò°æ±ŸÐÅÏ¢
//
******************************************************/
//
//

void Program_Edit()
{
   uchar page_number,column_number;
   uint piexl=MIN;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
      Write_Command(START_PAGE+page_number);
      Write_Command(START_HIGH_BIT);
      Write_Command(START_LOW_BIT);
      for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
      {
		 Write_Data(tab_1[piexl]);
		 piexl++;
	  }
  }
} 
void V_pinture()
{
   uchar page_number,column_number;
   uint piexl=MIN;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
      Write_Command(START_PAGE+page_number);
      Write_Command(START_HIGH_BIT);
      Write_Command(START_LOW_BIT);
      for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
      {
		 Write_Data(tab_V[piexl]);
		 piexl++;
	  }
  }
} 

//
//
/******************************************************
//
//ÍŒÆ¬Œì²âº¯Êý
//
******************************************************/
//
//

void Photo_Show()
{
   uchar page_number,column_number;
   uint piexl=MIN;
   for(page_number=MIN;page_number<PAGE_TOTAL/2;page_number++)
   {
      Write_Command(START_PAGE+page_number);
      Write_Command(START_HIGH_BIT);
      Write_Command(START_LOW_BIT);
      for(column_number=MIN;column_number<COLUMN_MAX;column_number++)
      {
		 Write_Data(tab_2[piexl]);
		 piexl++;
	  }
  }
}

//
//




