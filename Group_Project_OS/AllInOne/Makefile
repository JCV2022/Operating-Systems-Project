CC = gcc
OBJ = main.o 

prog1: main.o 
	$(CC) -o prog1 main.o -lm
	@echo 'Run program by ./prog1 (number of child 1 - 25)'
	@echo 'Please read README.txt for test specifications.'
	@ls

main.o: main.c 
	$(CC) -c main.c

clean:
	@echo 'Deleting files...'
	rm -f prog1 *.o
	@ls