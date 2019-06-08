#include "config.h"
#include "lcdWrite.h"
#include "byteLcd.h"
#include <stdio.h>
void move_ball(void)
{
  static uchar index = 0; 
  uchar w;
  const  bool upper_pos[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0};    // up and down positions
  const  bool start_pos_up[8] = {0xe0,0x70,0x38,0x1c,0x0e,0x07,0x03,0x01};
  
  const bool start_pos_dwn[8] = {0x07,0x0e,0x1c,0x38,0x70,0xe0,0xc0,0x80};
  const bool lower_pos[8] =     {0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03};
     //                         0    1     2    3   4     5     6   7   8     9     10  11  12   13   14   15   16  
  lcdWrite(SET_Y|row, LOW);
  lcdWrite(SET_X|col, LOW);
  if(z == 0 && col <85)    
  {
      if(col >=25)
            {
                row = row + 1;
            }
      else if(col >= 49)
            {
                row = row + 2;
            }
      else if (col >= 73)
            {
                row = row + 3;
            }
    for(index = 0; index <8; index++)
    {
        for (w = 0; w < 3; w++)
        {
            
            lcdWrite(SET_X|col, LOW);
            lcdWrite(SET_Y|row, LOW);
            lcdWrite(start_pos_dwn[index]|gameplay_area[row][col], HIGH);
            lcdWrite(SET_X|col, LOW);
            lcdWrite(SET_Y|row+1, LOW);
            if(row > 0)
            {
                lcdWrite(lower_pos[index]|gameplay_area[row][col], HIGH);
            }
            else
            {
                lcdWrite(lower_pos[index], HIGH);   
            }
            //printf("col = %d\n", col);
            col++;   
        }
    
        
    }
    
    
  }
  
}
  
  
  
  
  
