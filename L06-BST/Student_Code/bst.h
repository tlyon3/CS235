#pragma once
#include "BSTInterface.h"
#include "node.cpp"

class BST: public BSTInterface
{
private:
	Node* root;
public:
	BST(){}
	~BST(){}
	Node* getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();	
	bool addItemAt(Node* & n,int data);
	bool removeItemAt(Node* & n, int data);
	int size();
	int sizeAtN(Node* n);
	int minValueAtN(Node* n);
};