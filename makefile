all: main.o randfile.o
	gcc -o program main.o randfile.o

main.o: main.c randfile.h
	gcc -c main.c

randfile.o: randfile.c randfile.h
	gcc -c randfile.c

run:
	./program.exe

clean:
	rm *.o
	rm*~
