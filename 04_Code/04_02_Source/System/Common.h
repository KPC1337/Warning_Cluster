typedef unsigned char	U1;		/*1 Byte*/
typedef unsigned short	U2;		/*2 Byte*/	
typedef unsigned long	U4;		/*4 Byte*/

typedef signed char		S1;		/*1 Byte*/
typedef signed short	S2;		/*2 Byte*/	
typedef signed long		S4;		/*4 Byte*/

typedef unsigned char	D1;		/*BCD Data*/
typedef unsigned short	D2;		/*BCD Data*/	
typedef unsigned long	D4;		/*BCD Data*/

#define D 	P2_0
#define CLK P2_1
#define OE 	P2_2

#define HI 1
#define LO 0
#define NULL 0
#define OFF  (U1)0
#define ON   (U1)1
#define U1_MAX (U1)0xFF
#define U1_MIN (U1)0x00
#define TT_LN  (U1)0X08

typedef union{			/*Struct flag*/
	U1 u1_BYTE;			/*BYTE*/
	struct{
		U1 b00 : 1;	/*Bit 0*/
		U1 b01 : 1;	/*Bit 1*/
		U1 b02 : 1;	/*Bit 2*/
		U1 b03 : 1;	/*Bit 3*/
		U1 b04 : 1;	/*Bit 4*/
		U1 b05 : 1;	/*Bit 5*/
		U1 b06 : 1;	/*Bit 6*/
		U1 b07 : 1;	/*Bit 7*/
	}Bit;
}F1;

#define BIT0	(U1)1
#define BIT1	(U1)2
#define BIT2	(U1)4
#define BIT3	(U1)8
#define BIT4	(U1)0x10
#define BIT5	(U1)0x20
#define BIT6	(U1)0x40
#define BIT7	(U1)0x80
