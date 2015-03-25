#pragma once
#include "NodeInterface.h"

class Node:public NodeInterface
{
public:
	Node* left;
	Node* right;
	//Node* parent;
	int item;
	Node()
	{
		//parent=NULL;
		left=NULL;
		right=NULL;
	}
	Node(int data)
	{
		left=NULL;
		right=NULL;
		item=data;
	}
	Node(int data,Node* l,Node* r)
	{
		item=data;
		left=l;
		right=r;
	}
	~Node(){}
	int getData();
	Node* getLeftChild();
	Node* getRightChild();
};