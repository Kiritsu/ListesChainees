CC=g++

main: main.o liste.o
main.o: main.cpp liste.h
liste.o: liste.cc liste.h

clean:
	rm *.o main
