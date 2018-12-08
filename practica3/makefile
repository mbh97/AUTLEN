CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := main

all: $(EXE)

alfabeto.o: alfabeto.c alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.c -o alfabeto.o

palabra.o: palabra.c palabra.h
	$(CC) $(CFLAGS) -c palabra.c -o palabra.o

transicion.o: transicion.c transicion.h
	$(CC) $(CFLAGS) -c transicion.c -o transicion.o

estado.o: estado.c estado.h
	$(CC) $(CFLAGS) -c estado.c -o estado.o

lambda.o: lambda.c lambda.h
	$(CC) $(CFLAGS) -c lambda.c -o lambda.o

afnd.o: afnd.c afnd.h
	$(CC) $(CFLAGS) -c afnd.c -o afnd.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

main: main.o afnd.o transicion.o estado.o palabra.o alfabeto.o lambda.o
	$(CC) $(CFLAGS) main.o afnd.o transicion.o estado.o palabra.o alfabeto.o lambda.o -o main

clean:
	rm -f *.o $(EXE)
