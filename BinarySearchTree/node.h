#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class node
{
public:
	int value;
	int tracker;
	node* left;
	node* right;
	node(int load);
	node();
	void inorder(node* root);
	void kth_smallest_element(node* root, int k);

};

#endif
