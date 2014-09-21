#include "text_render.h"
#define BLANK ' '

char array[100][100];
void  traverse(bx * box)
{
  
   for(int i  = box->ct_tp + 1;i< box->ct_bm;i++)
   {
      array[box->ct_rt][i] = '|';//bottom right 
      array[box->ct_lt][i] = '|';//bottom right 
   }
   for(int i  = box->ct_lt + 1;i< box->ct_rt;i++)
   {
      array[i][box->ct_bm] = '-';//bottom right 
      array[i][box->ct_tp] = '-';//bottom right 
   }

   array[box->ct_rt][box->ct_bm] = '/';//bottom right 
   array[box->ct_rt][box->ct_tp] = '\\';//top right
   array[box->ct_lt][box->ct_bm] = '\\';//bottom left
   array[box->ct_lt][box->ct_tp] = '/';//top left 

  if(box->cd_bx != NULL)traverse(box->cd_bx);
  if(box->sg_bx != NULL)traverse(box->sg_bx);
  return;
}

void text_render(bx * box)
{
   int w = box->ct_rt + 1;
   int h = box->ct_bm + 1;
   for(int i = 0;i<w;i++)
      for(int j = 0;j<h;j++)
         array[i][j] = BLANK;
     
   traverse(box);
   
   for(int i = 0; i <h;i++)
   {
      for(int j =0;j< w;j++)
      {
         printf("%c",array[j][i] );
      }
      printf("\n");
   }
}
