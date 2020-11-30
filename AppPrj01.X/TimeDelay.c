/*
 * File:   TimeDelay.c
 * Author: Punit Patel
 * 
 * Created on October 20, 2020, 5:52 AM
 */

//User Header Files
//#include "ChangeClk.h"
#include "xc.h"
#include "TimeDelay.h"

/* 
 * This function creates a delay using interrupts
 * argument time_ms is the  desired amount of delay needed in milliseconds
 */
unsigned int TMR2flag = 0;
void delay_ms(uint16_t time_ms)
{
	//T2CON Configuration
	T2CONbits.TSIDL = 0; //Continue module operation in Idle mode
	T2CONbits.T32 = 0; //Timer2 and Timer3 act as two 16-bit timers
	T2CONbits.TCS = 0; //Use Internal clock (Fosc/2)
//	T2CONbits.TCKPS1=0; //To Select Prescale as 8, bit 5 is 0
//	T2CONbits.TCKPS0=1; //To Select Prescale as 8, bit 4 is 1
	
	//Timer 2 interrupt configuration
	IPC1bits.T2IP = 2; // Set priority level of the timer
	IEC0bits.T2IE = 1; //Enable timer interrupt by setting the T2IE bit high
	IFS0bits.T2IF = 0; // clear timer 2 flag
	
	
	TMR2 = 0; //Reset timer to start from 0
	//Compute PR2
	PR2=time_ms << 4; //PR2=Desired time delay in ms /(Prescalar * 2/fclk * 1000). Works out to be 2*time_ms after simplification
	T2CONbits.TON=1; //Timer 2 is ON
	
	Idle();
	T2CONbits.TON=0;
	return;
}

//Timer 2 interrupt subroutine
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
	IFS0bits.T2IF=0; // Clear timer 2 interrupt flag
	IEC0bits.T2IE=0; //disable timer interrupt.
	T2CONbits.TON=0;
	return;
}