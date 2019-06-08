#include "config.h"
#include "clear_screen.h"
#include "set_game_area.h"
#include "draw_paddles.h"
#include "lcdWrite.h"
#include "draw_puck.h"
#include "byteLcd.h"
#include "move_ball.h"
void one_player(void)
{
   // uchar row, col, x, y;
    clear_screen();
    set_game_area();
    draw_paddles();
    //draw_puck();
   /********draw ball***************/
    move_ball();
   
    
}
