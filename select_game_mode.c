#include "config.h"
#include "write_char.h"
uchar select_game_mode(void)
{
    write_char(&P[0], 0, 0); 
    write_char(&r[0], 8, 0); 
    write_char(&e[0], 16, 0); 
    write_char(&s[0], 24, 0); 
    write_char(&s[0], 32, 0); 
    
    write_char(&o[0], 48, 0); 
    write_char(&n[0], 56, 0); 
    write_char(&c[0], 64, 0); 
    write_char(&e[0], 72, 0); 
    
    write_char(&f[0], 0, 1); 
    write_char(&o[0], 8, 1); 
    write_char(&r[0], 16, 1); 
    
    write_char(&one[0], 28, 1); 
    
    write_char(&p[0], 40, 1); 
    write_char(&l[0], 46, 1); 
    write_char(&a[0], 51, 1); 
    write_char(&y[0], 59, 1); 
    write_char(&e[0], 67, 1); 
    write_char(&r[0], 75, 1); 
    
    write_char(&o[0], 0, 2); 
    write_char(&r[0], 8, 2); 
    
    write_char(&t[0], 24, 2); 
    write_char(&w[0], 32, 2); 
    write_char(&i[0], 38, 2); 
    write_char(&c[0], 44, 2); 
    write_char(&e[0], 52, 2); 
    
    write_char(&f[0], 64, 2); 
    write_char(&o[0], 70, 2); 
    write_char(&r[0], 77, 2);
    
    write_char(&TWO[0], 0, 3); 
    
    write_char(&p[0], 16, 3); 
    write_char(&l[0], 24, 3); 
    write_char(&a[0], 32, 3); 
    write_char(&y[0], 40, 3); 
    write_char(&e[0], 48, 3); 
    write_char(&r[0], 56, 3); 
    write_char(&s[0], 64, 3);
    return 0;
}
