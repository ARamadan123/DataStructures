#include <iostream>
#include "node.h"
#include <stdio.h>
node::node(int load)
{
	this->load = load;
	this->next = NULL;
}
node::node()
{
	this->load = 0;
	this->next = NULL;
}
