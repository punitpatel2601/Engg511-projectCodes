/* 
 * File:   IOs.c
 * Author: Atif Pathan
 *
 * Created on October 20, 2020, 6:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "TimeDelay.h"
#include "ChangeClk.h"
#include <xc.h>

void IOinit(void)
{
    
    TRISBbits.TRISB8 = 0; // make RB8 as digital output - LED
    
    TRISAbits.TRISA2 = 1; // make RA2 as digital input - PB1
    CNPU2bits.CN30PUE = 1; // Enable pull up register on RA2/CN30
    
    TRISAbits.TRISA4 = 1; // make RA4 as digital input - PB2
    CNPU1bits.CN0PUE = 1; // Enable pull up register on RA4/CN0
    
    TRISBbits.TRISB4 = 1; // make RB4 as digital input - PB3
    CNPU1bits.CN1PUE = 1; // Enable pull up register on RB4/CN1
    return;
}

void IOcheck (void)
{
    while(PORTAbits.RA2 == 0) // PB1 is pressed
        {
            if ((PORTAbits.RA4 == 0)||(PORTBbits.RB4 == 0))// if PB2 or PB3 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
            }
            else // only PB1 is pressed and thus light blinks in 1 sec interval
            {
                Delay_ms(1000);
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }                
            }
        }
        while(PORTAbits.RA4 == 0) // PB2 is pressed
        {
            if ((PORTAbits.RA2 == 0)||(PORTBbits.RB4 == 0))// if PB1 or PB3 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
            }
            else // only PB2 is pressed and thus light blinks in 2 sec interval
            {
                Delay_ms(2000);
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }                 
            }
        }
        while(PORTBbits.RB4 == 0) // PB3 is pressed
        {
            if ((PORTAbits.RA2 == 0)||(PORTAbits.RA4 == 0))// if PB1 or PB2 is pressed
            {
                // 2 or more PB's are pressed so LED is always on
                LATBbits.LATB8 = 1;
            }
            else // only PB3 is pressed and thus light blinks in 3 sec interval
            {
                Delay_ms(3000);
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }  
            }
        }
        LATBbits.LATB8 = 0; // if no LEDs are pressed then LED is off
    
    return;
}