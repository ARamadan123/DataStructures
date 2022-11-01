#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class node {

public:
	int load; // load of node
	node* next; // pointer to next node
	node(int load); // constructor
	node();
};

#endif