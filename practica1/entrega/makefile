CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := main prueba

all: $(EXE)

alfabeto.o: src/alfabeto.c includes/alfabeto.h
	$(CC) $(CFLAGS) -c src/alfabeto.c -o alfabeto.o

palabra.o: src/palabra.c includes/palabra.h
	$(CC) $(CFLAGS) -c src/palabra.c -o palabra.o

transicion.o: src/transicion.c includes/transicion.h
	$(CC) $(CFLAGS) -c src/transicion.c -o transicion.o

estado.o: src/estado.c includes/estado.h
	$(CC) $(CFLAGS) -c src/estado.c -o estado.o

afnd.o: src/afnd.c includes/afnd.h
	$(CC) $(CFLAGS) -c src/afnd.c -o afnd.o

main.o: test/main.c
	$(CC) $(CFLAGS) -c test/main.c -o main.o

main: main.o afnd.o transicion.o estado.o palabra.o alfabeto.o
	$(CC) $(CFLAGS) main.o afnd.o transicion.o estado.o palabra.o alfabeto.o -o main

prueba.o: test/prueba.c
	$(CC) $(CFLAGS) -c test/prueba.c -o prueba.o

prueba: prueba.o afnd.o transicion.o estado.o palabra.o alfabeto.o
	$(CC) $(CFLAGS) prueba.o afnd.o transicion.o estado.o palabra.o alfabeto.o -o prueba

clean:
	rm -f *.o $(EXE)
