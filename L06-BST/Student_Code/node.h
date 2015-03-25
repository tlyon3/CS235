#pragma once
#include "NodeInterface.h"

class Node:public NodeInterface
{
public:
	Node* left;
	Node* right;
	int item;
	Node()
	{
		left=NULL;
		right=NULL;
	}
	Node(int data)
	{
		left=NULL;
		right=NULL;
		item=data;
	}
	~Node(){}
	int getData();
	Node* getLeftChild();
	Node* getRightChild();
};