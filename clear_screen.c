#include "config.h"
#include "lcdWrite.h"
void clear_screen(void)
{
    uchar x, y;
    for (y = 0; y < 6; y++)
    {
        lcdWrite(VERT_ADDR, LOW);
        lcdWrite(SET_Y|y, LOW);
        for(x = 0; x < 84; x++)
        {
            lcdWrite(HORIZ_ADDR, LOW);
            lcdWrite(SET_X|x, LOW);
            lcdWrite(0x00, HIGH);   // clear screen
        }
    }
}
