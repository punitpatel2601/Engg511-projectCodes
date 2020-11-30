/*
 * File:   main.c
 * Author: Punit Patel
 * 
 * Created on November 20, 2020, 9:20 PM
 */

// MPLAB header libraries
#include <xc.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

// User header files
#include "IOs.h"
#include "ChangeClk.h"

#pragma config FCKSM = CSECMD // Clock switching is enabled, clock monitor disabled

 //MACROS for Idle, Sleep modes
#define Nop() {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep() {__asm__ volatile ("pwrsav #0");}   //Sleep() - put MCU in sleep mode - CPU and some peripherals off
#define Idle() {__asm__ volatile ("pwrsav #1");}    //Idle() - put MCU in idle mode - only CPU off
#define dsen() {__asm__ volatile ("BSET DSCON, #15");} 


//MAIN

int main(void) {
    //Change clock to low power setting
	display(0); //display time of 00m00s
    
    NewClk(32); // 8 for 8 MHz; 500 for 500 kHz; 32 for 32 kHz//configure clock
    
    IOinit(); //Function call to initialize the IO ports
    
    while(1)
    {
        Idle(); // Function call to trigger reaction on output pins based on inputs
    }
    
    return 0;
}
