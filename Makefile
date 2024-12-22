HEADERS = log.h stack.h expr.h
OBJECTS = log.o stack.o expr.o

default = main.out

main.out:
	gcc -Wall main.c expr.c stack.c log.c -o main.out
