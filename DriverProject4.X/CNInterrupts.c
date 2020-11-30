/* 
 * File:   CNInteruppts.c
 * Author: Atif Pathan
 *
 * Created on November 1, 2020, 11:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p24F16KA101.h>
#include <xc.h>
#include "TimeDelay.h"
#include "UART2.h"
#include "IOs.h"
#include "CNInterrupts.h"
/*
 * 
 */

void Debounce_check(void)
{
    //Delay_ms(30); // delay it 30ms to make sure signal is debounced 
    IPC4bits.CNIP = 6; // second highest priority interrupt for CN
    IEC1bits.CNIE = 1; // enable CN interrupt
    IFS1bits.CNIF = 1; // set flag for the interrupt 
   
    return;
}

void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void)
{
    // if an interrupt occured set the global variables to indicate which 
    // button was pressed
    if(IFS1bits.CNIF == 1) 
    {
        if(PORTBbits.RB4 == 0)
        {
            CN1flag = 1; // PB 3 was pressed
        }
        else{
            CN1flag = 0;
        }
        if (PORTAbits.RA4 == 0)
        {
            CN0flag = 1; // PB 2 was pressed 
        }
        else{
            CN0flag = 0;
        }
        if (PORTAbits.RA2 == 0)
        {
            CN30flag = 1; //PB 1 was pressed
        }
        else{
            CN30flag = 0;
        }
    }
    IFS1bits.CNIF = 0;
    Nop();
}
