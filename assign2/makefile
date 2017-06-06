CC = cc
COPS =

all: assign1-0 assign1

assign1-0: assign1-0.c pslibrary.c
	$(CC) $(COPS) -o assign1-0 assign1-0.c pslibrary.c

assign1: assign1.c pslibrary.c
	$(CC) $(COPS) -o assign1 assign1.c pslibrary.c

clean:
	rm -f assign1-0 assign1 *.o

run1:
	assign1 3 8 7 3 6 3 2
run2:
	assign1 3 8 7 3 6 7 2
run3:
	assign1 4 8 7 3 6 1 2
run4:
	assign1 3 3 3 4 2 1 2
run5:
	assign1 3 3 2 3 2 1 2
run6:
	assign1 3 5 2 5 4 1 1

test1:
	assign1 3 8 7 3 6 3 2

test2:
	assign1 3 8 7 3 6 7 2

test3:
	assign1 4 8 7 3 6 1 2

test4:
	assign1 3 3 3 4 2 1 2

test5:
	assign1 3 3 2 3 2 1 2

test6:
	assign1 3 5 2 5 4 1 1

test7:
	assign1 3 4 1 7 3 7 2

test8:
	assign1 3 4 2 5 3 2 2

test9:
	assign1 3 3 5 5 2 3 5

test10:
	assign1 3 1 1 4 1 1 1

test11:
	assign1 3 1 1 1 1 1 1

test12:
	assign1 3 1 3 1 3 1 1
