CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image -lSDL2_ttf
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
mario: main.c $(SRC)
	$(CC) $(SRC) ../windows.c -o $@ $(CFLAGS)