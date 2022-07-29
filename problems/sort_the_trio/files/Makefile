
CC = gcc
CFLAGS = -Wall -Werror -g

all: sort_the_trio

sort_the_trio: sort_the_trio.c main.c 
	$(CC) $(CFLAGS) -o sort_the_trio main.c sort_the_trio.c

clean:
	rm -f sort_the_trio

