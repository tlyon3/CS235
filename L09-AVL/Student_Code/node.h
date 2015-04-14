#pragma once
#include "NodeInterface.h"

class Node: public NodeInterface
{
private:
	
public:
	Node* right;
	Node* left;
	int data;
	int height;
	Node()
	{
		right=NULL;
		left=NULL;
		data= -1;
		height= -1;
	}
	Node(int ndata)
	{
		right=NULL;
		left=NULL;
		data=ndata;
		height=-1;
	}
	Node(int ndata,Node* r,Node* l)
	{
		data=ndata;
		right=r;
		left=l;
		height=-1;
	}
	Node* getLeftChild();
	void setLeftChild(Node* n);
	Node* getRightChild();
	void setRightChild(Node* n);
	int getHeight();
	void setHeight(int height);
	int getData();
	void setData(int data);
	int balanceFactor(Node* n);
};