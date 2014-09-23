#include <X11/Xlib.h>
#include "xlib_render.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mul = 30;
GC gr_context1, gr_context2;
void  xtraverse(bx * box, Display *d, Window * w, int *s)
{

   if(box->gn%2)
   {
      XFillRectangle(d, *w, gr_context1, 
            box->ct_lt*mul,box->ct_tp*mul,
            ((box->ct_rt - box->ct_lt))*mul, 
            ((box->ct_bm - box->ct_tp))*mul); 
   }
   else
   {
      XFillRectangle(d, *w, gr_context2, 
            box->ct_lt*mul,box->ct_tp*mul,
            ((box->ct_rt - box->ct_lt))*mul, 
            ((box->ct_bm - box->ct_tp))*mul); 

   }

  if(box->cd_bx != NULL)xtraverse(box->cd_bx,d,w,s);
  if(box->sg_bx != NULL)xtraverse(box->sg_bx,d,w,s);
  return;
}
void xlib_render(bx * box)
{                  
         

   Display *d;
   Window w;
   XEvent e;
   char *msg = "Hello, World!";
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 
      10, 10, box->ct_rt*mul, box->ct_bm*mul, 1,
      BlackPixel(d, s), WhitePixel(d, s));
   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);
 
   //XDrawString(d, w, DefaultGC(d, s), 10, 50, msg, strlen(msg));
   XGCValues gr_values; 
   gr_values.function   = GXcopy; 
   gr_values.plane_mask = AllPlanes; 
   //gr_values.foreground = BlackPixel(d,s); 
   gr_values.foreground = 100;//BlackPixel(d,s); 
   gr_values.background = WhitePixel(d,s); 
   gr_context1=XCreateGC(d,w, GCFunction | GCPlaneMask | 
      GCForeground | GCBackground, &gr_values); 
   gr_values.function =   GXxor; 
   gr_values.foreground = 1000;//WhitePixel(d,s); 
   gr_values.background = 100;//BlackPixel(d,s); 
   gr_context2=XCreateGC(d,w, GCFunction | GCPlaneMask | 
      GCForeground | GCBackground, &gr_values); 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) 
      {
         xtraverse(box,d,&w,&s);
         //XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 10, 10);
      }
      if (e.type == KeyPress)
         break;
   }
 
   XCloseDisplay(d);
   return ;
}
