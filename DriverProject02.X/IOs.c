/*
 * File:   IOs.c
 * Author: Atif Pathan
 *
 * Created on October 13, 2020, 12:17 PM
 */


#include "xc.h"

long int global_counter;

void IOinit(void)
{
    AD1PCFG = 0xFFFF; // Turn all analog pins as digital  
    TRISBbits.TRISB8 = 0; // make RB8 as digital output - LED
    
    TRISAbits.TRISA2 = 1; // make RA2 as digital input - PB1
    CNPU2bits.CN30PUE = 1; // Enable pull up register on RA2/CN30
    
    TRISAbits.TRISA4 = 1; // make RA4 as digital input - PB2
    CNPU1bits.CN0PUE = 1; // Enable pull up register on RA4/CN0
    
    TRISBbits.TRISB4 = 1; // make RB4 as digital input - PB3
    CNPU1bits.CN1PUE = 1; // Enable pull up register on RB4/CN1
    return;
}

void IOcheck(void)
{     
    
        while(PORTAbits.RA2 == 0) // PB1 is pressed
        {
            if ((PORTAbits.RA4 == 0)||(PORTBbits.RB4 == 0))// if PB2 or PB3 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
                continue;
            }
            else // only PB1 is pressed and thus light blinks in 1 sec interval
            {
                //basically use this counter as a buffer to implement enough instructions to take up one second 
                global_counter = 0;
                while (global_counter < 100000)
                {
                    global_counter = global_counter + 1;
                }
				if(LATBbits.LATB8 == 0)
					LATBbits.LATB8 = 1;
				else
					LATBbits.LATB8 = 0;
            }
            continue;
        }
        while(PORTAbits.RA4 == 0) // PB2 is pressed
        {
            if ((PORTAbits.RA2 == 0)||(PORTBbits.RB4 == 0))// if PB1 or PB3 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
                continue;
            }
            else // only PB2 is pressed and thus light blinks in 2 sec interval
            {
                //basically use this counter as a buffer to implement enough instructions to take up two seconds
                global_counter = 0;
                while (global_counter < 300000)
                {
                    global_counter = global_counter + 1;
                }
               if(LATBbits.LATB8 == 0)
					LATBbits.LATB8 = 1;
				else
					LATBbits.LATB8 = 0;
            }
            continue;
        }
        while(PORTBbits.RB4 == 0) // PB3 is pressed
        {
            if ((PORTAbits.RA2 == 0)||(PORTAbits.RA4 == 0))// if PB1 or PB2 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
                continue;
            }
            else // only PB3 is pressed and thus light blinks in 3 sec interval
            {
                //basically use this counter as a buffer to implement enough instructions to take up three seconds
                global_counter = 0;
                while (global_counter < 200000)
                {
                    global_counter = global_counter + 1;
                }
               if(LATBbits.LATB8 == 0)
					LATBbits.LATB8 = 1;
				else
					LATBbits.LATB8 = 0;
            }
            continue;
        }
        LATBbits.LATB8 = 0; // if no LEDs are pressed then LED is off
    
    return;
}