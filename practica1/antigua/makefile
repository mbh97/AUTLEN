CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := main prueba

all: $(EXE)

alfabeto.o: alfabeto.c alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.c -o alfabeto.o

palabra.o: palabra.c palabra.h
	$(CC) $(CFLAGS) -c palabra.c -o palabra.o

transicion.o: transicion.c transicion.h
	$(CC) $(CFLAGS) -c transicion.c -o transicion.o

estado.o: estado.c estado.h
	$(CC) $(CFLAGS) -c estado.c -o estado.o

afnd.o: afnd.c afnd.h
	$(CC) $(CFLAGS) -c afnd.c -o afnd.o

main.o: pruebas/main.c
	$(CC) $(CFLAGS) -c pruebas/main.c -o main.o

main: main.o afnd.o transicion.o estado.o palabra.o alfabeto.o
	$(CC) $(CFLAGS) main.o afnd.o transicion.o estado.o palabra.o alfabeto.o -o main

prueba.o: pruebas/prueba.c
	$(CC) $(CFLAGS) -c pruebas/prueba.c -o prueba.o

prueba: prueba.o afnd.o transicion.o estado.o palabra.o alfabeto.o
	$(CC) $(CFLAGS) prueba.o afnd.o transicion.o estado.o palabra.o alfabeto.o -o prueba

clean:
	rm -f *.o $(EXE)
