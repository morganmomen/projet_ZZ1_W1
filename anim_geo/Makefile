CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image -lSDL2_ttf
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
rectangle_bounce: main.c
	$(CC) $(SRC) ../windows.c -o $@ $(CFLAGS)