#include "hashtable.h"
#include "slot.h"
#include <vector>
#include <stdio.h>

hashtable::hashtable(int size)
{
	this->num_of_slots = size;
	this->slots.resize(num_of_slots);
}
int hashtable::hashingfunction(int element)
{
	return (element/this->num_of_slots); // our hashing function, if the number = 99 then 99/10 = 9, so 99 belongs in slot 9
}
void hashtable::add(int element)
{
	int index = hashingfunction(element); // finding slot number through the hashing function
	slots[index].insertNode(element); // inserting into given slot
}
void hashtable::remove(int element)
{
	int index = hashingfunction(element); // finding slot number through the hashing function
	slots[index].removeNode(element); // removing from given slot
}
void hashtable::printTable()
{
	for (int i = 0; i < this->num_of_slots; i++)
	{
		std::cout <<"slot " << i << ": ";
		slots[i].traverse();
		std::cout << std::endl;
	}
}
int hashtable::isExist(int value)
{
	int index = hashingfunction(value); // finding slot number through the hashing function
	return slots[index].traverseUntilValue(value); // returns 1 if value exists and 0 otherwise
}
void hashtable::removeDuplicate(hashtable &table)
{	
	for (int i = 0; i < this->num_of_slots; i++) // go through all slots
	{
		node* temp = this->slots[i].head;
		while (temp != NULL) // traversing linked list
		{
			//int flag = table.isExist(temp->load);
			if (!table.isExist(temp->load))
			{
				table.add(temp->load);
			}
			temp = temp->next;
		}
	}
}
