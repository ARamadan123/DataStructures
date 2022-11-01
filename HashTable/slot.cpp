#include "slot.h"
#include "node.h"
#include <stdio.h>
#include <iostream>
slot::slot(int load)
{
	head = new node(load);
}
slot::slot()
{
	head = NULL;
}

void slot::insertNode(int data)
{
	if (this->head == NULL) // if head is null then make the new node the head
	{
		this->head = new node(data);
		return;
	}
	node *new_node = new node(data);

	node *head = this->head;
	// find last node
	while (head->next != NULL)
	{
		head = head->next;
	}
	// append new node to last node
	head->next = new_node;
	return;

}
void slot::traverse()
{
	node* head = this->head;
	while (head != NULL) // traverse linked list and print load along the way
	{
		std::cout << head->load << " ";
		head = head->next;
	}

}
void slot::removeNode(int data)
{
	node* temp = this->head;
	node* prev = NULL;
	while (temp->load != data)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL)
	{
		this->head = this->head->next;
		return;
	}
	if (temp->next == NULL)
	{
		prev->next = NULL;
		return;
	}
	prev->next = temp->next;
	temp = NULL;

}
int slot::traverseUntilValue(int value)
{
	// 1 if value exists
	// 0 if value does not exist
	node* head = this->head;
	while (head != NULL)
	{
		if (head->load == value)
			return 1;
		head = head->next;
	}
	return 0;

}



