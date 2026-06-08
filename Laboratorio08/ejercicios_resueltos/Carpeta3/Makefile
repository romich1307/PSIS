CC = gcc
OBJ = main.o lista.o

all: programa

programa: $(OBJ)
	$(CC) $(OBJ) -o programa

main.o: main.c lista.h
	$(CC) -c main.c

lista.o: lista.c lista.h
	$(CC) -c lista.c

run: programa
	./programa

clean:
	rm -f *.o programa