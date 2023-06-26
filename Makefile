CC = gcc
CFLAGS = -Wall -Wextra -g -lSDL2 -lSDL2_image -lSDL2_ttf
LDFLAGS =
SRC = *.c
HEADERS = *.h
OBJ = $(SRC:%.c=%.o)
all : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	