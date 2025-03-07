#Makefile
all: sum_nbo

sum_nbo: sum_nbo.o
	g++ -o sum_nbo sum_nbo.o

sum_nbo.o: sum_nbo.cpp
	g++ -c -o sum_nbo.o sum_nbo.cpp

clean:
	rm -f sum_nbo
	rm -f *.o
