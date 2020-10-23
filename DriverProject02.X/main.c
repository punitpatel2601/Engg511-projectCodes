/*
 * File:   main.c
 * Author: Punit Patel
 *
 * Created on October 16, 2020, 7:58 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#include "IOs.h"

//int global_counter = 0;

void main (void){
    
    IOinit(); // initialize IO ports   
    
    while(1)
    {
        IOcheck(); // Implement IO checks and LED blinking    
    }
    
    return;
}

