#include <iostream>
#include <stdio.h>
#include <vector>
#include "node.h"

std::vector<int> bubbleSort(std::vector<int> v);
void printVector(std::vector<int> v);
node vectorToBST(std::vector<int> vec, node Node);

int main()
{
	// vector which will be used as the input
	std::vector<int> input = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };
	int k;

	std::cout << "Enter K: ";
	std::cin >> k;

	// print initial vector
	std::cout << "initial vector: ";
	printVector(input); // function to print the vector

	std::cout << std::endl;

	// sorts then prints the vector
	input = bubbleSort(input); // sort the vector from lowest to highest
	std::cout << "sorted vector: ";
	printVector(input); // printed sorted vector
	std::cout << std::endl;

	node* Root = new node(); // root of the tree
	*Root = vectorToBST(input, *Root);
	
	std::cout << std::endl << "inorder traversal of Final BST:" << std::endl;
	Root->inorder(Root);
	
	std::cout << std::endl;

	Root->kth_smallest_element(Root, k);
	



	return 0;
}

std::vector<int> bubbleSort(std::vector<int> v)
{
	int temp;

	for (int i = 0; i < v.size() -1; i++)
	{
		for (int j = 0; j < (v.size() - i-1); j++)
		{
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}

		}

	}
	return v;
}
void printVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
		

}
node vectorToBST(std::vector<int> vec, node Node)
{
	int median = vec.size()/2; // find median of vector

	Node.value = vec[median];

	std::vector<int> left_vector;

	for (int l = 0; l < median; l++)
	{
		left_vector.resize(l+1);
		left_vector[l] = vec[l];
	}
	if (!left_vector.empty())
	{
		Node.left = new node();
		*Node.left = vectorToBST(left_vector, *Node.left);
	}
	std::vector<int> right_vector;
	int m = 0;
	for (int r = median + 1; r < vec.size(); r++)
	{
		right_vector.resize(m + 1);
		right_vector[m] = vec[r];
		m++;
	}
	if (!right_vector.empty())
	{
		Node.right = new node();
		*Node.right = vectorToBST(right_vector, *Node.right);
	}
	return Node;
}
