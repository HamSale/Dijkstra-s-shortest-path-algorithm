#
# makefile
#
CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: dsp

dsp: main.o
	$(CC) -o dsp main.o

main.o: main.c
	$(CC) -c main.c -o main.o $(LIB)

clean:
	del -f dsp.exe
	del -f *.o
