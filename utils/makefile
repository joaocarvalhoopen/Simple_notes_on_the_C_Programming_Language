CC           = gcc
CFLAGS       = -O2 -std=c11 -Wall -Werror
RM           = rm -f

CFLAGS       = -g -std=c11 -Wall

default: all

all: list_test

jco_list.o: jco_list.c
	$(CC) $(CFLAGS) -o jco_list.o jco_list.c

main.o: main.c
	$(CC) $(CFLAGS) -o main.o main.c

list_test: main.c jco_list.c
	$(CC) $(CFLAGS) -o list_test main.c jco_list.c

clean:
	$(RM) list_test
	$(RM) main.o
	$(RM) jco_list.o