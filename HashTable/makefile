hash: node.o slot.o hashtable.o Source.o
	g++ node.o slot.o hashtable.o Source.o -o hash
node.o:	node.cpp node.h
	g++ -c node.cpp
slot.o: slot.cpp slot.h node.h
	g++ -c slot.cpp
hashtable.o: hashtable.cpp hashtable.h slot.h
	g++ -c hashtable.cpp
Source.o: Source.cpp hashtable.h
	g++ -c Source.cpp
clean:
	rm *.o
	rm hash
run: hash
	./hash
