all: exec

exec: main.o StringCAL.o
	g++ -g main.o StringCAL.o -o exec -Wall -Wextra -std=c++11

main.o : main.cpp StringCAL.h
	g++ -g -c main.cpp -o main.o -Wall -Wextra -std=c++11

StringCAL.o : StringCAL.h StringCAL.cpp
	g++ -g -c StringCAL.cpp -o StringCAL.o -Wall -Wextra -std=c++11
  
clean:
	rm *.o 
