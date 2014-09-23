all:main

CFLAGS:=-std=c99 -lX11

main: sbox.o text_render.o xlib_render.o 

text_render.c : sbox.c
*.o:*.h

clean:
	rm -f *.o
	rm -f main
