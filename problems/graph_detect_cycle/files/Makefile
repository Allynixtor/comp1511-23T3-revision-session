
CC = gcc
CFLAGS = -Wall -Werror -g

all: test_graph_detect_cycle

test_graph_detect_cycle: test_graph_detect_cycle.c graph_detect_cycle.c Graph.c
	$(CC) $(CFLAGS) -o test_graph_detect_cycle test_graph_detect_cycle.c Graph.c graph_detect_cycle.c

clean:
	rm -f test_graph_detect_cycle

