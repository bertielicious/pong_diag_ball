#include "config.h"
#include "lcdWrite.h"
void writeGameplayArea(void)
{
    uchar row, col = 0;
    for(row = 0; row < 6; row++)
    {
        lcdWrite(VERT_ADDR, LOW);       //vertical addressing mode
        lcdWrite(SET_Y|row, LOW);       // set row address
        for (col = 0; col < 84; col++)
        {
            if(gameplay_area[row][col] == 0)
            {
                continue;
            }
            else
            {
               lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
               lcdWrite(SET_X|col, LOW);   // set column address
               lcdWrite(gameplay_area[row][col], HIGH);    // write the data stored at array[row][col] to the LCD
            }
        }
    } 
}
