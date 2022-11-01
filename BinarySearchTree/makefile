BST: node.o Source.o
	g++ node.o Source.o -o BST
node.o: node.cpp node.h
	g++ -c node.cpp
Source.o: Source.cpp node.h
	g++ -c Source.cpp
clean:
	rm *.o
	rm BST
run: BST
	./BST
