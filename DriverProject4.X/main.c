/*
 * File:   main.c
 * Author: Atif Pathan
 *
 * Created on October 20, 2020, 6:41 PM
 */

#include <xc.h>

#include <p24fxxxx.h>
#include <p24F16KA101.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

// User header files
#include "IOs.h" 
#include "UART2.h"
#include "CNInterrupts.h"
#include "TimeDelay.h"


//Preprocessor directives - Configuration bits for MCU start up
#pragma config FCKSM = CSECMD // Clock switching is enabled, clock monitor disabled


// MACROS for Idle, Sleep modes
#define Nop() {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep() {__asm__ volatile ("pwrsav #0");}   //Sleep() - put MCU in sleep mode - CPU and some peripherals off
#define Idle() {__asm__ volatile ("pwrsav #1");}    //Idle() - put MCU in idle mode - only CPU off
#define dsen() {__asm__ volatile ("BSET DSCON, #15");} //

unsigned int CN30flag = 0; // for PB 1
unsigned int CN0flag = 0; // for PB 2
unsigned int CN1flag = 0; // for PB 3

//MAIN
void main(void) {
     
    //change clock
    NewClk(32);
    
   // Initialize IOs for low-power wake-up
    AD1PCFG = 0xFFFF; // Turn all analog pins as digital
    IOinit();
    while(1)
    {
        IOcheck();	 
        
        //reset flags
        //CN30flag = 0;
        //CN0flag = 0;n
        //CN1flag = 0;
    }
        
    return;
}



