#include "config.h"
#include "write_char.h"
void splash_screen(void)
{
    write_char(&P[0], 20, 2); 
    write_char(&P[0], 20, 2);
    write_char(&TWO[0], 30, 1);
    write_char(&O[0], 30, 2);
    write_char(&N[0], 40, 2);
    write_char(&THREE[0], 48, 1);
    write_char(&G[0], 50, 2);
    write_char(&EX[0], 60, 2);
    write_char(&BAT[0], 0, 1);
   // write_char(&BALL[0], 68, 4);
    write_char(&TAB[0], 75, 4);
}
