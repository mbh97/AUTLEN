CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := main

all: $(EXE)

alfabeto.o: src/alfabeto.c include/alfabeto.h
	$(CC) $(CFLAGS) -c src/alfabeto.c -o alfabeto.o

palabra.o: src/palabra.c include/palabra.h
	$(CC) $(CFLAGS) -c src/palabra.c -o palabra.o

transicion.o: src/transicion.c include/transicion.h
	$(CC) $(CFLAGS) -c src/transicion.c -o transicion.o

estado.o: src/estado.c include/estado.h
	$(CC) $(CFLAGS) -c src/estado.c -o estado.o

lambda.o: src/lambda.c include/lambda.h
	$(CC) $(CFLAGS) -c src/lambda.c -o lambda.o

afnd.o: src/afnd.c include/afnd.h
	$(CC) $(CFLAGS) -c src/afnd.c -o afnd.o

main.o: test/main.c
	$(CC) $(CFLAGS) -c test/main.c -o main.o

main: main.o afnd.o transicion.o estado.o palabra.o alfabeto.o lambda.o
	$(CC) $(CFLAGS) main.o afnd.o transicion.o estado.o palabra.o alfabeto.o lambda.o -o main

clean:
	rm -f *.o $(EXE)
