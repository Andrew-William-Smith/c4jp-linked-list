.DEFAULT_GOAL := all
CFLAGS := -g -std=c17 -Wall -Wextra

all: test

test: linked_list.h linked_list.c student.h student.c test.h test.c
	$(CC) $(CFLAGS) linked_list.c student.c test.c -o ll_test

run_test: test
	./ll_test

clean:
	-rm -f ll_test
