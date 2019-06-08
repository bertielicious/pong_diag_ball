#include "config.h"
#include "lcdWrite.h"
void byteLcd(uchar row, uchar col, uchar data)
{
    lcdWrite(VERT_ADDR, LOW);    // vertical addressing mode
    lcdWrite(SET_Y|row, LOW);    // sets vertical address to 0-5 rows
    
    lcdWrite(HORIZ_ADDR, LOW);   // horizontal addressing mode
    lcdWrite(SET_X|col, LOW);    // sets column address to 0 - 83 columns
    
    lcdWrite(data, HIGH);        // write a byte of data at address Y = row, X = col
}
