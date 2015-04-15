#pragma once
#include "NodeInterface.h"

class Node: public NodeInterface
{
private:
	
public:
	Node* right;
	Node* left;
	Node* parent;
	int data;
	int height;
	Node()
	{
		right=NULL;
		left=NULL;
		data= -1;
		parent=NULL;
		height=0;
	}
	Node(int ndata)
	{
		right=NULL;
		left=NULL;
		data=ndata;
		parent=NULL;
		height=0;
	}
	Node(int ndata,Node* r,Node* l)
	{
		data=ndata;
		right=r;
		left=l;
		parent=NULL;
		height=0;
	}
	Node(int key, Node* nparent)
	{
		data=key;
		left=NULL;
		right=NULL;
		parent=nparent;
		height=0;
	}
	~Node(){};
	Node* getLeftChild();
	void setLeftChild(Node* n);
	Node* getRightChild();
	void setRightChild(Node* n);
	int getHeight();
	// void setHeight(Node*);
	int getData();
	void setData(int data);
	string nodeInfo();
};