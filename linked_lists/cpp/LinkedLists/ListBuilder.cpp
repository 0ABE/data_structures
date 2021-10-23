#include "ListBuilder.h"

Node* ListBuilder::build(int initValue, size_t listSize)
{
	// create the head node
	Node *head = new Node(initValue);

	// append more nodes to the head starting with the next value
	head->append(++initValue, listSize - 1);

	return head;
}
