CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image -lSDL2_ttf
SRC = *.c
OBJ = $(SRC:%.c=%.o)
all : $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS)