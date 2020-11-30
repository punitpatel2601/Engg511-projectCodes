/*
 * File:   ADC.c
 * Author: Punit Patel
 *
 * Created on November 26, 2020, 1:50 AM
 */


#include "xc.h"
#include "ChangeClk.h"
#include "Output.h"
#include "UART2.h"



uint16_t do_ADC(void){
    
    uint16_t ADCval; //used to hold ADC's value 
    
    // Initialization
    
    AD1CON1bits.ADON = 1;       // power on
    AD1CON1bits.FORM = 0b00;    // setting output bits, integer format
    AD1CON1bits.SSRC = 0b111;   // sampling and start conversion
    AD1CON1bits.ASAM = 0;       // Sampling begins when SAMP bit is set
    
    AD1CON2bits.VCFG = 0b000;   // Selects AVDD
    AD1CON2bits.CSCNA = 0;      // no input scanning
    AD1CON2bits.SMPI = 0b0000;  // Enable interrupts when conversion is completed
    AD1CON2bits.BUFM = 0;       // Configures buffer as 16 bit
    AD1CON2bits.ALTS = 0;       // Sets MUX A input multiplexer to be used all time
    
    AD1CON3bits.ADRC = 0;       // Use system clock
    AD1CON3bits.SAMC = 0b11111; // Set sample time to be 1/10th of signal
    AD1CON3bits.ADCS = 0b11111; // Analog to Digital Conversion
    
    AD1CHSbits.CH0NA = 0;
    AD1CHSbits.CH0SA = 0b0101;
    
    // Input Output pins
    AD1PCFG = 0x0000;
    AD1CSSL = 0x0000;
    
    // Sampling and conversion
    
    AD1CON1bits.SAMP = 1;
    
    while(AD1CON1bits.DONE == 0){}
    
    ADCval = ADC1BUF0;
    
    AD1CON1bits.SAMP = 0;
    AD1CON1bits.ADON = 0;
    
    return ADCval;
}