#include <iostream>
#include <stdio.h>
#include "hashtable.h"

#include <time.h>
void fillTable(int count, hashtable &table);

int main()
{
	int num_of_slots = 10; // number of slots
	hashtable g1(num_of_slots); // initialize a new hashtable
	fillTable(1000, g1); // fill out table with 1000 random numbers between 10-99 inclusive
	
	std::cout << "Initial table: " << "\n";
	g1.printTable();
	
	hashtable no_duplicates(num_of_slots); // initialize a new table
	g1.removeDuplicate(no_duplicates); // remove duplicates
	int k;
	while (1)
	{
		std::cout << "\n";
		std::cout << "Enter number of slot to display after removing duplicates(10 to exit program): ";
		std::cin >> k;
		if (k > 9 || k < 0)
			break;
		std::cout << "\n";
		std::cout << "slot " << k << ": ";
		no_duplicates.slots[k].traverse();
		std::cout << "\n";
	}



	

	return 0;
}
void fillTable(int count, hashtable &table)
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		int num = rand() % 90 + 10;
		table.add(num);

	}

}
