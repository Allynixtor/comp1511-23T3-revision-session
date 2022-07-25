
CC = gcc
CFLAGS = -Wall -Werror -g

all: test_problem_template

test_problem_template: test_problem_template.c problem_template.c other_files.c
	$(CC) $(CFLAGS) -o test_problem_template test_problem_template.c other_files.c problem_template.c

clean:
	rm -f test_problem_template

