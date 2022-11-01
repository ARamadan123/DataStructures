#ifndef SLOT_H_EXISTS
#define SLOT_H_EXISTS
#include "node.h"
class slot {
	// this class is based on a single slot
public:
	node *head; // a slot will contain the head pointer of the linked list
	slot(int load); // constructor
	slot();
	void traverse(); // traversing through linked list 
	void insertNode(int data); // inserting a node add the end of linked list
	void removeNode(int data); // removing a node from the linked list
	int traverseUntilValue(int value); // traversing until a value is met
	// the function is used to check if a value exists in a slot
};

#endif



