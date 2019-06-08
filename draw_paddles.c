#include "config.h"
#include "lcdWrite.h"
#include "writeGameplayArea.h"
void draw_paddles(void)
{
    uchar row, col;
    uchar Y = 3;
    gameplay_area[Y][0] = paddle;   // draw paddle starting position on row 5 column 0
    //writeGameplayArea(); 
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
}
