CC = g++
CFLAGS =

go: main.o board.o printer.o
	$(CC) $(CFLAGS) -o go  main.o board.o printer.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

board.o: board.cpp
	$(CC) $(CFLAGS) -c board.cpp

printer.o: printer.cpp
	$(CC) $(CFLAGS) -c printer.cpp

.PHONY:
	all
	clean

all:
	make go

clean:
	rm -f go main.o board.o printer.o
