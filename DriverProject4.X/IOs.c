/* 
 * File:   IOs.c
 * Author: Atif Pathan
 *
 * Created on October 20, 2020, 6:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "TimeDelay.h"
#include "UART2.h"
#include <xc.h>
#include "CNInterrupts.h"


void IOinit(void)
{
    TRISBbits.TRISB8 = 0; // make RB8 as digital output - LED
    
    TRISAbits.TRISA2 = 1; // make RA2 as digital input - PB1
    CNEN2bits.CN30IE = 1; // enable to configure the IO as a change of notification
    CNPU2bits.CN30PUE = 1; // Enable pull up register on RA2/CN30
    
    TRISAbits.TRISA4 = 1; // make RA4 as digital input - PB2
    CNEN1bits.CN0IE = 1; // enable to configure the IO as a change of notification
    CNPU1bits.CN0PUE = 1; // Enable pull up register on RA4/CN0
    
    TRISBbits.TRISB4 = 1; // make RB4 as digital input - PB3
    CNEN1bits.CN1IE = 1; // enable to configure the IO as a change of notification 
    CNPU1bits.CN1PUE = 1; // Enable pull up register on RB4/CN1
    return;
}

void IOcheck (void)
{
    while((PORTAbits.RA2 == 0)&&(PORTAbits.RA4 == 1)&&(PORTBbits.RB4 == 1)) // only PB1 is pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 0) || (CN0flag == 1) || (CN1flag == 1)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                Delay_ms(470); // 500 - 30
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }
                Disp2String("\r PB1 is pressed         ");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 1)&&(PORTAbits.RA4 == 0)&&(PORTBbits.RB4 == 1)) // only PB2 is pressed
    {
            Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 1) || (CN0flag == 0) || (CN1flag == 1)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                Delay_ms(1970); // 2000 - 30
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }
                Disp2String("\r PB2 is pressed         ");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 1)&&(PORTAbits.RA4 == 1)&&(PORTBbits.RB4 == 0)) // only PB3 is pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 1) || (CN0flag == 1) || (CN1flag == 0)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                Delay_ms(2970); //3000 - 30
                if(LATBbits.LATB8 == 1){
                    LATBbits.LATB8 = 0;
                }
                else{
                    LATBbits.LATB8 = 1;
                }
                Disp2String("\r PB3 is pressed         ");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 0)&&(PORTAbits.RA4 == 0)&&(PORTBbits.RB4 == 1)) // only PB1 and PB2 are pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 0) || (CN0flag == 0) || (CN1flag == 1)) // check if the flags are still the same after the delay
                    break;
                else
                {  
                LATBbits.LATB8 = 1; // keep LED on
                Disp2String("\r PB1 and PB2 are pressed");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 0)&&(PORTAbits.RA4 == 1)&&(PORTBbits.RB4 == 0)) // only PB1 and PB3 are pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 0) || (CN0flag == 1) || (CN1flag == 0)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                LATBbits.LATB8 = 1; // keep LED on
                Disp2String("\r PB1 and PB3 are pressed");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 1)&&(PORTAbits.RA4 == 0)&&(PORTBbits.RB4 == 0)) // only PB2 and PB3 are pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 1) || (CN0flag == 0) || (CN1flag == 0)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                LATBbits.LATB8 = 1; // keep LED on
                Disp2String("\r PB2 and PB3 are pressed");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    while((PORTAbits.RA2 == 0)&&(PORTAbits.RA4 == 0)&&(PORTBbits.RB4 == 0)) // all 3 PBs are pressed
    {
        Delay_ms(30); // delay to ensure the debounce effects are taken care of
                Debounce_check();
                if ((CN30flag == 0) || (CN0flag == 0) || (CN1flag == 0)) // check if the flags are still the same after the delay
                    break;
                else
                {      
                LATBbits.LATB8 = 1; // keep LED on
                Disp2String("\r All PBs are pressed      ");
                }    
                //reset the flags again before another interrupt 
                CN30flag = 0; 
                CN0flag = 0; 
                CN1flag = 0;
    }
    
    // else no PBs are pressed
    LATBbits.LATB8 = 0; // if no PBs are pressed then LED is off
    Disp2String("\r Nothing pressed         ");
    return;
}

