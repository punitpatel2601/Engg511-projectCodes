/*
 * File:   IOs.c
 * Author: Punit Patel
 * 
 * Completed on November 5th, 2020
 */


//User Header Files
#include "TimeDelay.h"
#include "ChangeClk.h"
#include "IOs.h"
#include "UART2.h"

int8_t countPB1 = 0; // minutes tracker
int8_t countPB2 = 0; // seconds trackerstatic 
uint8_t timer = 0;
int8_t checkPB3 = 0; // flag


/* 
 * Initializes the input and output ports.
 */
void IOinit(void)
{
	AD1PCFG = 0xFFFF;       // Turn all analog pins as digital
	TRISBbits.TRISB8 = 0;   //Makes GPIO RB8 as digital output
	TRISAbits.TRISA4 = 1;   //Makes GPIO RA4 as a digital input
	TRISBbits.TRISB4 = 1;   //Makes GPIO RB4 as a digital input
    TRISAbits.TRISA2 = 1;   //Makes GPIO RA2 as a digital input
	
	CNPU1bits.CN0PUE = 1;   //Enables pull up resistor on RA4/CN0
	CNPU1bits.CN1PUE = 1;   //Enables pull up resistor on RB4/CN1
	CNPU2bits.CN30PUE = 1;  //Enables pull up resistor on RA2/CN30
	IPC4bits.CNIP = 3;      //button interrupts should be prioritized higher than timer.
	CNEN1bits.CN0IE = 1;    //enable interrupts for RA4/CN0, RB4/CN1, and RA2/CN30
	CNEN1bits.CN1IE = 1; 
	CNEN2bits.CN30IE = 1;
	IEC1bits.CNIE = 1;      //Enable CN Interrupt by setting the CNIE bit high
	
	return; 
}

void display(uint8_t timeUP)
{
	char output[] = "\r00 M : 00 S            ";
	output[1] = (countPB1 / 10) + 48;       //adds 10s digit to output array as character
	output[2] = (countPB1 % 10) + 48;       //adds 0s digit to output array as character
    output[4] = 'M';
	output[8] = (countPB2 / 10) + 48;       //adds 10s digit to output array as character
	output[9] = (countPB2 % 10) + 48;       //adds 0s digit to output array as character
    output[11] = 'S';
	if(timeUP == 1)                      //if time is 0:0
    {                     
		char* timeUP = " --ALARM  ";   //set alarm text
		int8_t i = 0;
		while(i < 10)
        {                  //creating output array
			output[12+i] = timeUP[i];
			i++;
		}
	}
	sendToUART(output);                 //display output text
}

void sendToUART(char* string)
{ 
    IEC1bits.CNIE = 0;      //Disable CN Interrupt.
	NewClk(8);              // Speed up the clock to 8 mhz
	Disp2String(string);
	NewClk(32);             // slow back down to 32.
	IEC1bits.CNIE = 1;      //Enable CN Interrupt again.
}

void updateTime()
{
    display(0);             //display current time.
	LATBbits.LATB8 = 0;     
	if(PORTAbits.RA2 == 0)      // when pb1 is pressed
		while(PORTAbits.RA2 == 0) 
        {
			timer = 0;
			countPB1 = (countPB1+1)%60;     //increment minutes in 0 to 59
			display(0);                     //display updated time
			delay_ms(200);                  //wait a little while before looping
		}
	else if(PORTAbits.RA4 == 0)                 //when pb2 is pressed
		while(PORTAbits.RA4 == 0) 
        {
			timer = 0;
			countPB2 = (countPB2+1)%60;     //increment second in 0 to 59
			display(0);         //display updated time
			delay_ms(200);      //wait a little while before looping
		}
	else if(PORTBbits.RB4 == 0)     //or only if this button is pressed
		while(PORTBbits.RB4 == 0)
        { 
			checkPB3 = 1; //enable checkPB3 flag
			delay_ms(3000);//wait 3 seconds for no button updates.

			if((PORTBbits.RB4 == 0) && (checkPB3 == 1))
            {
				checkPB3 = 0;
				timer = 0;
				countPB1 = 0;       //set min to 0
				countPB2 = 0;       //set sec to 0
				display(0); 
				break;
			}
			else 
                return;
		}
	if((checkPB3 == 1) && (PORTBbits.RB4 == 1))
    { 
		timer ^= 1;         //start the timer loop.
		checkPB3 = 0;       //disable checkPB3 flag.
		
		while((PORTAbits.RA2 == 1) && (PORTBbits.RB4 == 1) && (PORTAbits.RA4 == 1) && (timer == 1))
        { 
            LATBbits.LATB8 = 0; //turn off the light before we start.
            delay_ms(900);  // waiting before looping
			if(timer == 0) 
                return;     //exit if timer is stopped
			if(countPB2 == 0 && countPB1 == 0) 
            { //if no time is left
				LATBbits.LATB8 = 1;     //turn light on
				display(1);             //display time with alarm flag
				timer = 0;              //stop timer
				return;
			}
            else if(countPB2-- == 0)
            { 
				countPB2 = 59;      //if sec is 0, set it to 59
				countPB1 --;        // subtract min
			}
			LATBbits.LATB8 = 1;     //flash light
			delay_ms(10);           //short delay to turn it off and on noticably.
			display(0);             //display current time
		}
	}
    return;
}

/* 
 * Changes in output based on changes in inputs.
 */
void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void)
{
	IEC0bits.T2IE = 0;      //disable timer interrupt
	T2CONbits.TON = 0;      //disable timer
	IEC1bits.CNIE = 0;      //Disable CN Interrupt.
	delay_ms(50);           //ensuring any debounces within 200ms never influences the running program.
	IEC1bits.CNIE = 1;      //Enable CN Interrupt again.
	IFS1bits.CNIF=0;        // Clear interrupt flag
	updateTime();
	
	return;
}