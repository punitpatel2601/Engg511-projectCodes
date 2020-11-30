/*
 * File:   main.c
 * Author: Punit Patel
 *
 * Created on November 24, 2020, 6:41 PM
 */

#include <xc.h>

#include <p24fxxxx.h>
#include <p24F16KA101.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

// User header files
#include "ADC.h" 
#include "UART2.h"
#include "Output.h"
#include "ChangeClk.h"


//Preprocessor directives - Configuration bits for MCU start up
#pragma config FCKSM = CSECMD // Clock switching is enabled, clock monitor disabled


// MACROS for Idle, Sleep modes
#define Nop() {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep() {__asm__ volatile ("pwrsav #0");}   //Sleep() - put MCU in sleep mode - CPU and some peripherals off
#define Idle() {__asm__ volatile ("pwrsav #1");}    //Idle() - put MCU in idle mode - only CPU off
#define dsen() {__asm__ volatile ("BSET DSCON, #15");} //

int lastBar;

//MAIN
void main(void) {
     
    //change clock
    NewClk(32);
    
    InitUART2();
    
   // Initialize IOs for low-power wake-up
    AD1PCFG = 0xFFFF; // Turn all analog pins as digital
   
    uint16_t bar;
    
    while(1)
    {
       bar = do_ADC(); // stores ADC value
       dispBar(bar);    //creatses bar graph form the ADC value stored in bar
    }   
        
    return;
}


