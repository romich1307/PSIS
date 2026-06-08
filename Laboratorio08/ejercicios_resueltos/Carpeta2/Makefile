CC = gcc

OBJ = main.o persona.o

all: programa

programa: $(OBJ)
	$(CC) $(OBJ) -o programa

main.o: main.c persona.h
	$(CC) -c main.c

persona.o: persona.c persona.h
	$(CC) -c persona.c

run: programa
	./programa

clean:
	rm -f *.o programa

rebuild: clean all

install: programa
	mkdir -p bin
	cp programa bin/

uninstall:
	rm -f bin/programa

help:
	@echo "make        -> Compilar"
	@echo "make run    -> Ejecutar"
	@echo "make clean  -> Limpiar"
	@echo "make rebuild-> Reconstruir"
	@echo "make install -> Instalar"
	@echo "make uninstall -> Desinstalar"