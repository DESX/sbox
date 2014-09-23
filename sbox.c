#include <stdlib.h>
#include "sbox.h"

//void ssp(bx * box, int x, int y, int * x, int * y)
void ssq(bx * box, int x, int y,int * x_m, int * y_m)
{
   box->ct_lt = x;
   box->ct_tp = y;
   box->ct_rt = x+1;
   box->ct_bm = y+1;
   if(box->cd_bx != NULL)
   {
      int l_x_m = x; 
      int l_y_m = y; 
      ssq(box->cd_bx,x+1,y+1,&l_x_m, &l_y_m);
      box->ct_rt = l_x_m+1;
      box->ct_bm = l_y_m+1;
   }
   if(box->sg_bx != NULL)
   {
      ssq(box->sg_bx,box->ct_rt+1,box->ct_tp, x_m,y_m);
   }
   if((x_m != NULL)&&(box->ct_rt > *x_m))*x_m = box->ct_rt;
   if((y_m != NULL)&&(box->ct_bm > *y_m))*y_m = box->ct_bm;
   return; 
}
bx * add(bx* pt)
{
   bx * cd = malloc(sizeof(bx));
   if(pt!=NULL)
   {
      cd->gn = pt->gn+1;
      cd->sg_bx = pt->cd_bx;
      pt->cd_bx = cd;
      cd->pt_bx = pt;//we have a parent 
   }
   else
   {
      cd->sg_bx = NULL;
      cd->pt_bx = NULL;//we have a parent 
      cd->gn = 0;
   }
   cd->cd_bx = NULL;//no children 
   return cd;
}
void del_box(bx*box)
{
   if(box->cd_bx != NULL)del_box(box->cd_bx);
   if(box->sg_bx != NULL)del_box(box->sg_bx);
   free(box);
   return;
}

