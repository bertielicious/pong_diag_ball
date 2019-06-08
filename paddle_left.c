#include "config.h"
#include "lcdWrite.h"
#include "writeGameplayArea.h"
#include <stdio.h>
void paddle_left(void)
{ 
    uchar row, col = 0;
    static uchar  y = 1;
    static uchar x = 0;     // counts number of left button presses
    static uchar Y = 3;   // initial vertical position of the paddle
    static uchar X = 0;     // horizontal position of the paddle
    bool upper_pos[9] = {0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};    // up and down positions
    bool start_pos[9] = {0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};
    
    if(PORTAbits.RA4 == 0 && PORTCbits.RC2 == 1)              //left/ up button is pressed
    {  
        if(x > 8)
        {
            x = 0;
            Y = Y - 1;
        }
        
        gameplay_area[Y-y][0] = upper_pos[x];
        gameplay_area[Y][0] = start_pos[x];
      /*  printf("x = %d\n", x);
        printf("Y = %d\n", Y);
        printf("upper_pos = %x\n",upper_pos[x]);
        printf("start_pos = %x\n",start_pos[x]);*/
        
    for(row = 0; row < 6; row++)
    {
        lcdWrite(VERT_ADDR, LOW);       //vertical addressing mode
        lcdWrite(SET_Y|row, LOW);       // set row address
        col = 0;
        {
           
            lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
            lcdWrite(SET_X|col, LOW);   // set column address
            lcdWrite(gameplay_area[row][col], HIGH);    // write the data stored at array[row][col] to the LCD
        }
    }  
        if(Y >=1)
        {
            x++;
        }
        
        
    }
    
    else if(PORTCbits.RC2 == 0 && PORTAbits.RA4 == 1)
    {
        if (x > 7)
       
        {
            x = 7;  
            Y = Y + 1;  
            
        }
        
       
       
        gameplay_area[Y-y][0] = upper_pos[x];
        gameplay_area[Y][0] = start_pos[x];
        /*printf("x = %d\n", x);
        printf("Y = %d\n", Y);
        printf("upper_pos = %x\n",upper_pos[x]);
        printf("start_pos = %x\n",start_pos[x]);*/
        for(row = 0; row < 6; row++)
    {
        lcdWrite(VERT_ADDR, LOW);       //vertical addressing mode
        lcdWrite(SET_Y|row, LOW);       // set row address
        col = 0;
        {
           
            lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
            lcdWrite(SET_X|col, LOW);   // set column address
            lcdWrite(gameplay_area[row][col], HIGH);    // write the data stored at array[row][col] to the LCD
        }
    }  
       
      if(Y <=5)
        {
            x--;
        }  
    } 
}
