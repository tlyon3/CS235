#pragma once
#include "NodeInterface.h"

class Node:public NodeInterface
{
public:
	Node* root;
	Node* left;
	Node* right;
	int item;
	Node(){}
	~Node(){}
	int getData();
	Node* getLeftChild();
	Node* getRightChild();
};