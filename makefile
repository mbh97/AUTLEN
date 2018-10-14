CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := testA testP testT testE main

all: $(EXE)

alfabeto.o: alfabeto.c alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.c -o alfabeto.o

testA.o: testA.c
	$(CC) $(CFLAGS) -c testA.c -o testA.o

testA: testA.o alfabeto.o
	$(CC) $(CFLAGS) testA.o alfabeto.o -o testA

palabra.o: palabra.c palabra.h
	$(CC) $(CFLAGS) -c palabra.c -o palabra.o

testP.o: testP.c
	$(CC) $(CFLAGS) -c testP.c -o testP.o

testP: testP.o palabra.o
	$(CC) $(CFLAGS) testP.o palabra.o -o testP

transicion.o: transicion.c transicion.h
	$(CC) $(CFLAGS) -c transicion.c -o transicion.o

testT.o: testT.c
	$(CC) $(CFLAGS) -c testT.c -o testT.o

testT: testT.o transicion.o
	$(CC) $(CFLAGS) testT.o transicion.o -o testT

estado.o: estado.c estado.h
	$(CC) $(CFLAGS) -c estado.c -o estado.o

testE.o: testE.c
	$(CC) $(CFLAGS) -c testE.c -o testE.o

testE: testE.o transicion.o estado.o
	$(CC) $(CFLAGS) testE.o transicion.o estado.o -o testE

afnd.o: afnd.c afnd.h
	$(CC) $(CFLAGS) -c afnd.c -o afnd.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

main: main.o transicion.o estado.o palabra.o alfabeto.o
	$(CC) $(CFLAGS) main.o transicion.o estado.o palabra.o alfabeto.o -o main



clean:
	rm -f *.o $(EXE)
