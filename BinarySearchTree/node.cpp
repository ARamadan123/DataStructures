#include <iostream>
#include <stdio.h>
#include "node.h"


node::node(int load)
{
	value = load;
	left = NULL;
	right = NULL;
	tracker = 0;

}
node::node()
{
	left = NULL;
	right = NULL;
	tracker = 0;
}
void node::inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->value << " ";
		inorder(root->right);
	}

}

void node::kth_smallest_element(node* root, int k)
{
	if (root != NULL)
	{
		//std::cout << root->value;
		kth_smallest_element(root->left, k); // recursively visit the leftmost node
		this->tracker++; // increment everytime a node is visited starting from the leftmost node
		if (this->tracker == k) 
		{
			std::cout << "the kth smallest element is: " << root->value << std::endl;
		}
		kth_smallest_element(root->right, k); // search right subtree
	}
}
