
CC = gcc
CFLAGS = -Wall -Werror -g

all: sort_the_trio

sort_the_trio: sort_the_trio.c test_sort_the_trio.c 
	$(CC) $(CFLAGS) -o sort_the_trio test_sort_the_trio.c sort_the_trio.c

clean:
	rm -f sort_the_trio

