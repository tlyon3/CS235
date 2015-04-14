#pragma once
#include "AVLInterface.h"
#include "node.h"

class AVL : public AVLInterface
{
private:
	Node* root;
public:
	Node* getRootNode();
	bool add(int data);
	bool addItemAt(Node*& n, int data);
	bool remove(int data);
	Node* removeItemAt(Node*& n,int data);
	Node* findNode(Node* n,int data);
	int maxValueAtN(Node* n);
	Node* rotateRight(Node* n);
	Node* rotateLeft(Node* n);
	void fixHeight(Node* n);
	Node* balance(Node* p);
	int balanceFactor(Node*);
	Node* findMinNode(Node*);
	Node* removeMinNode(Node*);
};