all: main

main: main.o String.o
	g++ main.o String.o -o main
  
StringCAL.o : StringCAL.h StringCAL.cpp
	g++ -g -c StringCAL.cpp -o StringCAL.o -std=c++11
  
clean:
	rm -f *.o 
