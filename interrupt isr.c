#include "config.h"
#include "interrupt isr.h"
#include "paddle_left.h"
#include "byteLcd.h"
#include "move_ball.h"

void interrupt isr(void)
{
    
    if ( INTCONbits.TMR0IF = 1)
    {
        //GREEN_LED = ~GREEN_LED;
         paddle_left();      // put this in a 1ms interrupt routine
         TMR0 = 0x00; 
         INTCONbits.TMR0IF = 0; 
    }
    if (PIR1bits.TMR1IF == 1 )       // TMR1 is 1 sec gravity timer interrupt
    {
        if(z == 0)                     // run erase ball code
        {
        z = 1;
        TMR1H = 0xf0;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0xf5;
        }
        else if (z == 1)
        {
            
        z = 0;
        TMR1H = 0xc0;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
        }
        move_ball();
        GREEN_LED = ~GREEN_LED;
        
        PIR1bits.TMR1IF = 0;
    }
}
