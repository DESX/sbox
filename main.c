#include <stdio.h>
#include "sbox.h"
#include "text_render.h"

int main(int argc, char** argv)
{
   printf("----creating  ----\n");
   bx * b00 = add(NULL); 
   bx * b01 = add(b00);
   bx * b02 = add(b00);
   bx * b03 = add(b00);
   bx * b04 = add(b00);
   bx * b05 = add(b00);
   bx * b06 = add(b00);
   bx * b07 = add(b00);
   bx * b08 = add(b00);
   bx * b09 = add(b00);
   bx * b10 = add(b00);
   bx * b11 = add(b02);
   printf("----populating----\n");
   ssp(b00,0,0);
   printf("----rendering ----\n");
   text_render(b00);
}
