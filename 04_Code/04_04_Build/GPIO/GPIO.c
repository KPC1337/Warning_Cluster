#include <89c51rd2.h>

#define ON 	(U1)1
#define OFF	(U1)0
#define u1_NoPort  (U1)4

typedef unsigned char U1;

U1 u1_GetPortData(U1, U1);


U1 u1_PortData[4]; 
/*
0 Default data
1 10ms sample
2 20ms sample
3 30ms sample
4 CRD
*/

int main(void)
{

    return(0);
}

void chatterRemoval(){



}

U1 u1_GetPortData(U1 u1_Port, U1 u1_Pos)
{
	U1 u1_work;
	
	u1_work = (U1)OFF;
	if(u1_Port < u1_NoPort)
	{
		u1_work = u1_PortData[4]&u1_Pos;
		if(u1_work != 0)
		{
			u1_work = (U1)ON;
		}
	}
	return(u1_work);	
}