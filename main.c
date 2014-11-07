#include <stdio.h>
#include "sbox.h"
#include "text_render.h"
#include "xlib_render.h"

int main(int argc, char** argv)
{
   printf("----creating  ----\n");
   bx * b00 = add(NULL); 
   add(b00);
   add(b00);
   add(b00);
   add(b00);
   add(b00);
   bx * b03 = add(b00);
   add(b03);
   bx * b04 = add(b00);
   add(b04);
   bx * b05 = add(b00);
   bx * b06 = add(b00);
   bx * b07 = add(b00);
   bx * b08 = add(b00);
   bx * b09 = add(b00);
   bx * b10 = add(b00);

   printf("----populating----\n");
   ssq(b00,0,0,NULL,NULL);

   //ssp(b00,0,0);
   printf("----text rendering ----\n");
   text_render(b00);
   //printf("----x11 rendering ----\n");
   //xlib_render(b00);
   del_box(b00);
}
