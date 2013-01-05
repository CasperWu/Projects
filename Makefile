VPATH=../Packages

all: test clean

test: test.o
	gcc -o test test.o
test.o: test.c
	gcc -c test.c
clean:
	rm test.o
