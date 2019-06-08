#include"config.h"
uchar player_sel(void)
{
    static uchar player_num = 0;
    if(SWIP == 1 && current_state == NOT_PRESSED)
    {
        previous_state = NOT_PRESSED;
        current_state = NOT_PRESSED;
    }
    else if (SWIP == 0 && previous_state == NOT_PRESSED && current_state == NOT_PRESSED)
    {
        previous_state = NOT_PRESSED;
        current_state =  PRESSED;
        player_num++;
    }
    else if(SWIP == 1 && previous_state == NOT_PRESSED && current_state == PRESSED)
    {
        previous_state = PRESSED;
        current_state = PRESSED;
    }
    else if (SWIP == 0 && previous_state == PRESSED && current_state == PRESSED)
    {
        previous_state = PRESSED;
        current_state =  NOT_PRESSED;
        player_num++;
    }
    if(player_num > 2)
    {
        player_num = 0;
    }
    return player_num;
}
