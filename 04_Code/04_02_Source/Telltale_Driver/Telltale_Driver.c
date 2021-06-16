#include"Telltale_Driver.prm"	

void TT_Dr_Init(void)
{
	D 	= HI;
	CLK = HI;
	OE 	= LO;
}

void TT_Dr_Write(U1 TTData)
{
	S1 s1_i;
	OE=LO;
	for(s1_i = (S1)7; s1_i >= (S1)0; s1_i--)
	{
		D = (TTData>>s1_i)&(U1)0x01;
		CLK = LO;
		CLK = HI;
	}
	OE=HI; 

}


/*
static void TT_Dr_allTTOn(void);
static void TT_Dr_allTTOff(void);
static void TT_Dr_Lightshow(void);
static void delay(U2 Delay_Time);
*/


/*

static void TT_Dr_allTTOn(void)
{
	TT_Dr_Write((U1)0x00);
}

static void TT_Dr_allTTOff(void)
{
	TT_Dr_Write((U1)0xFF);
}

static void TT_Dr_Lightshow(void)
{
	U1 u1_i;
	U1 TTData;
	TTData = (U1)0X01;
	for(u1_i = (U1)0; u1_i <= TT_LN; u1_i++)
	{
		TT_Dr_Write(TTData^(U1)0xFF);	
		TTData = TTData<<1;	
		delay((U2)0X0064);
	}
	
	TTData = (U1)0X80;
	for(u1_i = (U1)0; u1_i < TT_LN; u1_i++)
	{
		TT_Dr_Write(TTData^(U1)0xFF);	
		TTData = TTData>>1;	
		delay((U2)0X0064);
	}

	TTData = (U1)0X01;
	for(u1_i = (U1)0; u1_i < TT_LN; u1_i++)
	{
		TT_Dr_Write(TTData);	
		TTData = TTData<<1;	
		delay((U2)0X0064);
	}
	
	TTData = (U1)0X80;
	for(u1_i = (U1)0; u1_i <= TT_LN; u1_i++)
	{
		TT_Dr_Write(TTData);	
		TTData = TTData>>1;	
		delay((U2)0X0064);
	}
}

static void delay(U2 Delay_Time)
{
	U2 count;  

	count = (U2)0X0000;

		while(count<=Delay_Time)
		{
		TMOD=0x01;  
		TH0=0xFC; 
		TL0=0x18; 
		TR0=1;      // Running the timer
		while(!TF0);   //Checking the timer flag register if it is not equal to 1 
		TR0 = 0;      // If TF0=1 stop the timer
		TF0 = 0;      // Clear the Timer Flag bit for next calculation

		count++;
		}

}		
*/