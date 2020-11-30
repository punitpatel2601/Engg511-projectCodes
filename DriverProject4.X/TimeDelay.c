/*
 * File:   TimeDelay.c
 * Author: Atif Pathan
 *
 * Created on October 20, 2020, 6:41 PM
 */

#include "CNInterrupts.h"
#include "xc.h"


void Delay_ms(uint16_t time_ms){
    
    unsigned int ClkVal = 10;
    INTCON1bits.NSTDIS = 1; // don't need nested interrupts
    T1CONbits.TCKPS = 0; // Pre-scalar is 1
    T1CONbits.TON = 1; // start timer1
    T1CONbits.TSIDL = 0; // continue operation in idle mode
    T1CONbits.TCS = 0; // choose internal clock = 32kHz
    TMR1 = 0; //clear TMR1
    IPC0bits.T1IP = 7; // set highest priority
    IEC0bits.T1IE = 1; // enable interrupt request for timer1
    
    PR1 = (time_ms*ClkVal); // calculate the PR1 value
   
    Idle(); // idle while it increments TMR1 to match PR1
    return;
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0; // clear interrupt flag for timer1
    T1CONbits.TON = 0; // stop timer 
}
