/* 
 * File:    main.c
 * Author:  Punit Patel
 * UCID:    30064251
 * Lab:     7
 * Tut.:    1
 *
 * Created on October 2, 2020, 6.43 AM
 */

#include <xc.h>

int main(void) {
    
    // using port A for input
   
    TRISAbits.TRISA0=1; 
    // sets RA0-GPIO2  as input 
    TRISAbits.TRISA1=1; 
    // sets RA1-GPIO3  as input 
    TRISAbits.TRISA4=1;
    // sets RA4-GPIO10 as input 
    TRISAbits.TRISA6=1; 
    // sets RA6-GPIO14 as input 
    
    
    // using port B for output
   
    TRISBbits.TRISB0=0;  
    // sets RB0-GPIO4   as output 
    TRISBbits.TRISB4=0; 
    // sets RB4-GPIO9   as output 
    TRISBbits.TRISB7=0; 
    // sets RB7-GPIO11  as output 
    TRISBbits.TRISB8=0; 
    // sets RB8-GPIO12  as output 
    TRISBbits.TRISB9=0;  
    // sets RB9-GPIO13  as output 
    TRISBbits.TRISB12=0;
    // sets RB12-GPIO15 as output 
    TRISBbits.TRISB13=0; 
    // sets RB13-GPIO16 as output 
    TRISBbits.TRISB14=0; 
    // sets RB14-GPIO17 as output 

    while(1)
    {  
        // 0 LEDs ON
        if (PORTAbits.RA0==0 && PORTAbits.RA1==0 && PORTAbits.RA4==0 && PORTAbits.RA6==0)
        {
          LATBbits.LATB0 = 0;     //sets RB0 to low
          LATBbits.LATB4 = 0;     //sets RB4 to low
          LATBbits.LATB7 = 0;     //sets RB7 to low
          LATBbits.LATB8 = 0;     //sets RB8 to low          
          LATBbits.LATB9 = 0;     //sets RB9 to low
          LATBbits.LATB12 = 0;    //sets RB12 to low
          LATBbits.LATB13 = 0;    //sets RB13 to low
          LATBbits.LATB14 = 0;    //sets RB15 to low
        }

        //this condition checks for 1st digit of UCID which is 3
        else  if (PORTAbits.RA0==0 && PORTAbits.RA1==0 && PORTAbits.RA4==0 && PORTAbits.RA6==1)        
        {
          LATBbits.LATB0 = 1;     //sets RB0 to high
          LATBbits.LATB4 = 1;     //sets RB4 to high
          LATBbits.LATB7 = 1;     //sets RB7 to high
          LATBbits.LATB8 = 0;     //sets RB8 to low
          LATBbits.LATB9 = 0;     //sets RB9 to low
          LATBbits.LATB12 = 0;    //sets RB12 to low
          LATBbits.LATB13 = 0;    //sets RB13 to low
          LATBbits.LATB14 = 0;    //sets RB14 to low
        }
         
        //this condition checks for 2nd digit of UCID which is 0
        else  if (PORTAbits.RA0==0 && PORTAbits.RA1==0 && PORTAbits.RA4==1 && PORTAbits.RA6==0)
        {
         LATBbits.LATB0 = 0;      //sets RB0 to low
         LATBbits.LATB4 = 0;      //sets RB4 to low
         LATBbits.LATB7 = 0;      //sets RB7 to low
         LATBbits.LATB8 = 0;      //sets RB8 to low
         LATBbits.LATB9 = 0;      //sets RB9 to low
         LATBbits.LATB12 = 0;     //sets RB12 to low
         LATBbits.LATB13 = 0;     //sets RB13 to low
         LATBbits.LATB14 = 0;     //sets RB14 to low
        }

        //this condition checks for 3rd digit of UCID which is 0
        else if (PORTAbits.RA0==0 && PORTAbits.RA1==0 && PORTAbits.RA4==1 && PORTAbits.RA6==1)
        {
          LATBbits.LATB0 = 0;     //sets RB0 to low
          LATBbits.LATB4 = 0;     //sets RB4 to low
          LATBbits.LATB7 = 0;     //sets RB7 to low
          LATBbits.LATB8 = 0;     //sets RB8 to low
          LATBbits.LATB9 = 0;     //sets RB9 to low
          LATBbits.LATB12 = 0;    //sets RB12 to low
          LATBbits.LATB13 = 0;    //sets RB13 to low
          LATBbits.LATB14 = 0;    //sets RB14 to low
        }
        
        //this condition checks for 4th digit of UCID which is 6   
        else if (PORTAbits.RA0==0 && PORTAbits.RA1==1 && PORTAbits.RA4==0 && PORTAbits.RA6==0)
        {
          LATBbits.LATB0 = 1;     //sets RB0 to high
          LATBbits.LATB4 = 1;     //sets RB4 to high
          LATBbits.LATB7 = 1;     //sets RB7 to high
          LATBbits.LATB8 = 1;     //sets RB8 to high
          LATBbits.LATB9 = 1;     //sets RB9 to high
          LATBbits.LATB12 = 1;    //sets RB12 to high
          LATBbits.LATB13 = 0;    //sets RB13 to low
          LATBbits.LATB14 = 0;    //sets RB14 to low
        }
                
        //this condition checks for 5th digit of UCID which is 4
        else if (PORTAbits.RA0==0 && PORTAbits.RA1==1 && PORTAbits.RA4==0 && PORTAbits.RA6==1)
        {
          LATBbits.LATB0 = 1;   //sets RB0 to high
          LATBbits.LATB4 = 1;   //sets RB4 to high
          LATBbits.LATB7 = 1;   //sets RB7 to high
          LATBbits.LATB8 = 1;   //sets RB8 to high
          LATBbits.LATB9 = 0;   //sets RB9 to low
          LATBbits.LATB12 = 0;  //sets RB12 to low
          LATBbits.LATB13 = 0;  //sets RB13 to low
          LATBbits.LATB14 = 0;  //sets RB14 to low
        }

        //this condition checks for 6th digit of UCID which is 2    
        else if (PORTAbits.RA0==0 && PORTAbits.RA1==1 && PORTAbits.RA4==1 && PORTAbits.RA6==0)
        {
          LATBbits.LATB0 = 1;   //sets RB0 to high
          LATBbits.LATB4 = 1;   //sets RB4 to high
          LATBbits.LATB7 = 0;   //sets RB7 to low
          LATBbits.LATB8 = 0;   //sets RB8 to low
          LATBbits.LATB9 = 0;   //sets RB9 to low
          LATBbits.LATB12 = 0;  //sets RB12 to low
          LATBbits.LATB13 = 0;  //sets RB13 to low
          LATBbits.LATB14 = 0;  //sets RB14 to low
        }

        //this condition checks for 7th digit of UCID which is 5
        else if (PORTAbits.RA0==0 && PORTAbits.RA1==1 && PORTAbits.RA4==1 && PORTAbits.RA6==1)
        {
          LATBbits.LATB0 = 1;       //sets RB0 to high
          LATBbits.LATB4 = 1;       //sets RB4 to high
          LATBbits.LATB7 = 1;       //sets RB7 to high
          LATBbits.LATB8 = 1;       //sets RB8 to high
          LATBbits.LATB9 = 1;       //sets RB9 to high
          LATBbits.LATB12 = 0;      //sets RB12 to low
          LATBbits.LATB13 = 0;      //sets RB13 to low
          LATBbits.LATB14 = 0;      //sets RB14 to low
        }
        
        //this condition checks for 8th digit of UCID which is 1
        else if (PORTAbits.RA0==1 && PORTAbits.RA1==0 && PORTAbits.RA4==0 && PORTAbits.RA6==0)
        {
          LATBbits.LATB0 = 1;       //sets RB0 to high
          LATBbits.LATB4 = 0;       //sets RB4 to low
          LATBbits.LATB7 = 0;       //sets RB7 to low
          LATBbits.LATB8 = 0;       //sets RB8 to low
          LATBbits.LATB9 = 0;       //sets RB9 to low
          LATBbits.LATB12 = 0;      //sets RB12 to low
          LATBbits.LATB13 = 0;      //sets RB13 to low
          LATBbits.LATB14 = 0;      //sets RB14 to low
        }
        
        //  no LEDs turned ON for rest of the inputs
        else
        {
            LATBbits.LATB0 = 0;     //sets RB0 to low
            LATBbits.LATB4 = 0;     //sets RB4 to low
            LATBbits.LATB7 = 0;     //sets RB7 to low
            LATBbits.LATB8 = 0;     //sets RB8 to low
            LATBbits.LATB9 = 0;     //sets RB9 to low
            LATBbits.LATB12 = 0;    //sets RB12 to low
            LATBbits.LATB13 = 0;    //sets RB13 to low
            LATBbits.LATB14 = 0;    //sets RB14 to low
        }   
    }
   return 0; 
}

