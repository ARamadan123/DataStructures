#ifndef HASHTABLE_H_EXISTS
#define HASHTABLE_H_EXISTS
#include "slot.h"
#include <vector>
#include <iostream>
class hashtable {

public:
	int num_of_slots; // number of slots in hashtable, in our case it will be 10, 0-9
	std::vector<slot> slots; // a vector of slots 
	hashtable(int size); // constructor
	int hashingfunction(int element); // hashing function
	void add(int element); // adding an element to hashtable
	void remove(int element); // removing an element from hashtable
	void printTable(); // printing hashtable
	int isExist(int value); // checking if a value exists in hashtable
	void removeDuplicate(hashtable &table); // remove duplicate value from hashtable
};

#endif



