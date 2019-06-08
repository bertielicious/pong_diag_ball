#include "config.h"

#include "lcdWrite.h"
void write_char(uchar *character, uchar x, uchar y)
{
    uchar row, col = 0;
    row = y;
    col = x;
        lcdWrite(VERT_ADDR, LOW);   // vertical addressing mode
        lcdWrite(SET_Y|row, LOW);       // sets address at top LH corner (origin) of LCD
       // lcdWrite(sety|y, LOW);       // sets address at top LH corner (origin) of LCD)
        lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
        lcdWrite(SET_X|col, LOW);
        for (x= 0; x <8; x++)
        {
             lcdWrite(*character, HIGH);
             character++;
        }  
}
