#pragma once
#include "BSTInterface.h"
#include "node.h"

class BST: public BSTInterface
{
private:
	Node* root;
public:
	BST()
	{
		root=NULL;
	}
	~BST()
	{
		delete root;
	}
	Node* getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();	
	bool addItemAt(Node* &n,int data);
	bool removeItemAt(Node* & n, int data);
	int size();
	int sizeAtN(Node* n);
	int maxValueAtN(Node* n);
	void deleteTree(Node* n);
	Node* findNode(Node* n,int data);
};