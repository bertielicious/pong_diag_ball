#include "config.h"
#include "lcdWrite.h"
#include "writeGameplayArea.h"
void draw_puck(void)
{
    uchar row, col = 0;
    row = 5;
    lcdWrite(VERT_ADDR, LOW);
    lcdWrite(SET_Y|row, LOW);
    
    for(col = 0; col < 8; col++)
    {
        lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
        lcdWrite(SET_X|col, LOW);
        gameplay_area[row][col] = BALL[col]|gameplay_area[row][col];    // write BALL data into the gameplay_area array
        writeGameplayArea();
    }
  
}
