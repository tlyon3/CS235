#include "node.h"

int Node::getData()
{
	return this->item;
}

Node* Node::getLeftChild()
{
	return this->left;
}

Node* Node::getRightChild()
{
	return this->right;
}

