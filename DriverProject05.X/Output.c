/*
 * File:   Output.c
 * Author: Punit Patel
 *
 * Created on November 26, 2020, 1:53 AM
 */


#include "xc.h"
#include "ADC.h"

extern int lastBar;

void dispBar(uint16_t adc){
    int bGraph = (adc+1)/64; // getting value for bargraph
    NewClk(8);              //setting clock to 8
    
    XmitUART2('\r', 1);
    
    if(bGraph != lastBar){ // if last bar was not same then make new one
        lastBar = bGraph;
        XmitUART2(' ', 17);
        XmitUART2('\r',1);
        XmitUART2('|',1);
        XmitUART2('=',lastBar);
        XmitUART2(' ',(15-lastBar));
        XmitUART2('|',1);
    }
    
    XmitUART2('\r',1);
    XmitUART2('\t',3);
    Disp2Hex(adc);
    
    NewClk(32);     //slowing down again
    
    return;
}