#ifndef SBOX_H
#define SBOX_H
#include <stdio.h>
//--nouns:
//ct =coordinate
//pt =parent
//sg =sibling
//tn =twin
//cd =child 
//bx =box
//  
//--adjectives
//wt =width
//ht =height
//rt =right 
//lt =left 
//tp =top 
//bm =bottom 
//tr =top right 
//tl =top left 
//br =bottom right
//bl =bottom left  
//at =absolute coordinate, relatve to bottom left corner of most senior box
//rc =relative coordinate, reltive to bottom left corner of specific box
//gn =generation, the number of parents box has
//max = max
//min = min
//or = older
//yr = younger
//vertical coordinate/position is always listed first
typedef struct bx
{
   int gn;
   struct bx * pt_bx; 
   struct bx * sg_bx; 
   struct bx * cd_bx; 
   
   int ct_rt;
   int ct_lt;
   int ct_bm;
   int ct_tp;
}bx;

bx * add(bx*pt);
bx * spop(bx * pt,int x, int y);
void ssp(bx * box, int x, int y);

#endif
