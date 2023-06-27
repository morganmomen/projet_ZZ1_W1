CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image -lSDL2_ttf
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
window_bounce: main.c event_windows.c 
	$(CC) $(SRC) ../windows.c -o $@ $(CFLAGS)