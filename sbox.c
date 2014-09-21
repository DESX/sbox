#include <stdlib.h>
#include "sbox.h"

//void ssp(bx * box, int x, int y, int * x, int * y)
void ssp(bx * box, int x, int y)
{
   box->ct_lt = x;
   box->ct_tp = y;
   box->ct_rt = x+1;
   box->ct_bm = y+1;
   if(box->cd_bx != NULL)
   {
      ssp(box->cd_bx,x+1,y+1);
      bx * t = box->cd_bx;
      int ym = t->ct_rt; 
      int xm = t->ct_bm; 
      while(t != NULL)
      {
         if(t->ct_rt > ym) ym = t->ct_rt;
         if(t->ct_bm > xm) xm = t->ct_bm;
         t = t->sg_bx;
      }
      box->ct_rt = ym+1;
      box->ct_bm = xm+1;
   }
   if(box->sg_bx != NULL)
   {
      ssp(box->sg_bx,box->ct_rt+1,box->ct_tp);
   }
   return; 
}
bx * add(bx* pt)
{
   bx * _bx = malloc(sizeof(bx));

   int grt= 0;
   if(pt != NULL)
   {
      struct bx * i = pt->cd_bx;
      if(i == NULL)
      {
         pt->cd_bx = _bx;
      }
      else
      {
         while(i->sg_bx != NULL)
         {
            i=i->sg_bx;
            //l_grt= (i->grt > l_grt)?i->grt:l_grt;       
         }
         i->sg_bx   = _bx;//set as sibling
      }
      _bx->gn       = pt->gn + 1;//parents generation + 1
   }
   else
   {
      _bx->gn = 0;
   }

   _bx->pt_bx    = pt;//we have a parent 
   _bx->sg_bx    = NULL;//this is always the last sibling
   _bx->cd_bx    = NULL;//no children 

   return _bx;
}

