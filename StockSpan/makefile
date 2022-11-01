all: Source
	g++ bruteForce.o -o spanBruteForce
	g++ stack.o -o spanStack
Source: bruteForce.cpp stack.cpp
	g++ -c bruteForce.cpp
	g++ -c stack.cpp
clean: 
	rm *.o
	rm spanStack
	rm spanBruteForce
stack:
	./spanStack
bruteforce:
	./spanBruteForce
