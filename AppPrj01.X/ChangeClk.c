// Following code provided by Dr. Rushi Vyas
// Code used unmodified

#include "xc.h"
#include "ChangeClk.h"


//clkval = 8 for 8MHz; 
//clkval = 500 for 500kHz; 
//clkval = 32 for 32kHz; 
void NewClk(unsigned int clkval)  
{
	char COSCNOSC;
	if (clkval == 8)  //8MHz
    {
		COSCNOSC = 0x00;
	}
	else if (clkval == 500) // 500 kHz
	{
		COSCNOSC = 0x66;
	}
	else if (clkval== 32) //32 kHz
	{
		COSCNOSC = 0x55;
	}
	else // default 32 kHz
	{
		COSCNOSC = 0x55;
	}
	// Switch clock to 500 kHz
	SRbits.IPL = 7;  //Disable interrupts
	CLKDIVbits.RCDIV = 0;  // CLK division = 0
	__builtin_write_OSCCONH(COSCNOSC);   // (0x00) for 8MHz; (0x66) for 500kHz; (0x55) for 32kHz;
	__builtin_write_OSCCONL(0x01);
//	OSCTUNbits.TUN = 0b011111;
//	OSCCONbits.OSWEN=1; //comment out after video, was not needed as OSCCONL does the same thing.
	while(OSCCONbits.OSWEN==1)
	{}
	SRbits.IPL = 0;  //enable interrupts
}

