all: exec

exec: main.o StringCAL.o
	g++ main.o StringCAL.o -o exec -Wall -Wextra
  
StringCAL.o : StringCAL.h StringCAL.cpp
	g++ -g -c StringCAL.cpp -o StringCAL.o -Wall -Wextra -std=c++11
  
clean:
	rm *.o 
