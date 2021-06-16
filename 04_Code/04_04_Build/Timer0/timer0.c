#include <t89c51rd2.h>

typedef unsigned char  U1;
typedef unsigned short U2;
#define NULL 0;	

typedef union{
	U1 u1_BYTE;
	struct{
			U1 b00 : 1;
			U1 b02 : 1;
			U1 b03 : 1;
			U1 b04 : 1;
			U1 b05 : 1;
			U1 b06 : 1;
			U1 b07 : 1;
		  }Bit;
}F1;

typedef union{
	U2 u2_BYTE;
	struct{
			U2 b00 : 1;
			U2 b02 : 1;
			U2 b03 : 1;
			U2 b04 : 1;
			U2 b05 : 1;
			U2 b06 : 1;
			U2 b07 : 1;
			U2 b08 : 1;
			U2 b09 : 1;
			U2 b10 : 1;
			U2 b11 : 1;
			U2 b12 : 1;
			U2 b13 : 1;
			U2 b014 : 1;
		  }u2_word;
}F2;

#define OFF  (U1)0
#define ON   (U1)1

void Task_1(void);
void Task_2(void);
void Task_3(void);
void Event(void (*event_TBL[])(void));

U1 u1_BUF_1MS;
F1 St_Temp;

void (*const MS10_TBL[])(void) = {&Task_1,&Task_2,&Task_3};

int main(void)
{ 
	u1_BUF_1MS = (U1)OFF;
	St_Temp.Bit.b00 = ON;
	
	TMOD = 0x01;
	IE   = 0x82;
	TL0  = 0xD8;
    TH0  = 0xF0;
	TR0  = 1; 
	while(1)
	{
	  if(St_Temp.Bit.b00 == ON)
	  {
		  Event(MS10_TBL);
		  St_Temp.Bit.b00 = OFF;
		  EA = 1;
	  }	
	} 	
}

void Timer0(void) interrupt 1
{
  St_Temp.Bit.b00 = ON; 
  TF0 = 0; 
  TL0  = 0x18;
  TH0  = 0xFC;
  EA = 0;
}

void Task_1(void)
{
  P1_0 = ~(P1_0);	
}

void Task_2(void)
{
  P1_1 = ~(P1_1);	
}

void Task_3(void)
{
  P1_1 = ~(P1_1);	
}

void Event(void (*const *MS10_TBL)(void))
{
	for(; *MS10_TBL != 0 ;){
		(*MS10_TBL)();
		MS10_TBL++;
	}
}


