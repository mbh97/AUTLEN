CFLAGS := -g -Wall -pedantic
CC := gcc
EXE := testA testE testP

all: $(EXE)

alfabeto.o: alfabeto.c alfabeto.h
	$(CC) $(CFLAGS) -c alfabeto.c -o alfabeto.o

testA.o: testA.c
	$(CC) $(CFLAGS) -c testA.c -o testA.o

testA: testA.o alfabeto.o
	$(CC) $(CFLAGS) testA.o alfabeto.o -o testA

estado.o: estado.c estado.h
	$(CC) $(CFLAGS) -c estado.c -o estado.o

testE.o: testE.c
	$(CC) $(CFLAGS) -c testE.c -o testE.o

testE: testE.o estado.o
	$(CC) $(CFLAGS) testE.o estado.o -o testE
	
palabra.o: palabra.c palabra.h
	$(CC) $(CFLAGS) -c palabra.c -o palabra.o

testP.o: testP.c
	$(CC) $(CFLAGS) -c testP.c -o testP.o

testP: testP.o palabra.o
	$(CC) $(CFLAGS) testP.o palabra.o -o testP

clean:
	rm -f *.o $(EXE)
