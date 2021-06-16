/****************************************/
/* INCLUDE HEADER FILES*/
#include<t89c51rd2.h>
#include"Sys.prm"
#include"common.h"

/****************************************/
/*Main program*/
/****************************************/
void main(void)
{
	U1 u1_CNT;
	/*Initialization code*/
	SysTimer_Init();
	
	
	
	
	while(1)
	{
		/*Port data acquisition*/
		
		/* Event table*/
		
	}	
}

static void SysTimer_Init(void){
	TR0 = OFF;
	TL0 = 0xE0;
	TH0 = 0xB1;
}

void SysTimer_Run(void){
	TR0 = ON;
}

void SysTimer_Stop(void){
	TR0 = OFF;
}