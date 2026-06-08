CC = gcc

programa: main.o operaciones.o
	$(CC) main.o operaciones.o -o programa

main.o: main.c operaciones.h
	$(CC) -c main.c

operaciones.o: operaciones.c operaciones.h
	$(CC) -c operaciones.c

clean:
	rm -f *.o programa