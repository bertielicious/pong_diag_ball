/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 04 March 2019, 19:24
 * 
1) Keep your pull requests small and digestible
2) Write a design doc before coding to save time and prevent spaghetti code
3) Keep your eye on the end goal (i.e. shipping products) and don't surf reddit at work ¯\_(?)_/¯
4) Lose the ego and arrogance, don't be afraid to ask questions, and don't try to write "clever" unintelligible code
5) Respect The Tech Lead, buy them coffee or they'll get you fired?
 */
/* Design document for Pong game
 * This version of pong is a one (human) player game (LHS) who plays against the PIC microcontroller (RHS). Whenever the puck is successfully returned, 
 * one point is scored. When the puck is missed and goes out of play behind the paddle, a point is deducted from that player. 
 * Whoever is the first player to reach 10 is the winner. If the puck is returned from the top or bottom of the paddle, the angle of the deflected ball is 45 deg.
 * If the puck is returned from the middle area of the paddle, the angle of the return is 180 deg. The puck can only rebound from the top or bo ttom walls, 
 * not from the wall at extreme left or right of the screen. The game starts whenever the human moves the paddle for the first time.
 */

#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "clear_screen.h"
#include "set_game_area.h"
#include "write_char.h"
#include "splash_screen.h"
#include "select_game_mode.h"
#include "player_sel.h"
#include "one_player.h"
#include "two_player.h"
#include "paddle_left.h"
#include "writeGameplayArea.h"
#include "byteLcd.h"


void main(void) 
{ 
   uchar mode = 0;
   config_osc();
   setup_ports();
   init_spi();
   set_usart();
   lcd_setup();                // configures the LCD
  
   clear_screen();             // clears any random data presented on the LCD at power on
   //set_game_area();            // draws game play area on LCD
   splash_screen();            // display PONG! splash screen 
   __delay_ms(500);
   clear_screen();             // clears any random data presented on the LCD at power on
   select_game_mode();          // user selects from 0: computer plays itself 1: 1 player or 2: 2 player
   printf("mode = %d\n", mode);
   printf("hello pong\n");
   while(SWIP == 1);            // wait for game mode to be selected via SWIP going low once or twice
   mode = player_sel();
   while(SWIP == 1);            // wait for game mode to be selected via SWIP going low once or twice
   mode = player_sel();
   if(mode == 1)
   {
       one_player();            //if mode 1 selected call one_player
       printf("mode = %d\n", mode);
   }
   else if (mode == 2)
   {
       two_player();
       printf("mode = %d\n", mode);
   }
   
   mode = 0;
   printf("mode = %d\n", mode);
   TMR0_setup();
   TMR1_setup();
   
    while(1)
    {
        
        
    }
}