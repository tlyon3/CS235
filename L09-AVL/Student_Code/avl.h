#pragma once
#include "AVLInterface.h"
#include "node.h"

class AVL : public AVLInterface
{
private:
	Node* root;
public:
	AVL(){root=NULL;};
	~AVL(){};
	// bool singleRotateRight(Node*, Node*, Node*);
 //    bool singleRotateLeft(Node*, Node*, Node*);
 //    bool doubleRotateRight(Node*, Node*, Node*, Node*);
 //    bool doubleRotateLeft(Node*, Node*, Node*, Node*);
    // int getHeight(Node*);
    // bool add(int data);
    // Node* getRootNode();
    // bool rotate(Node*, Node*, Node*);
    // bool isBalanced(Node*);
    // void updateTreeBal(Node*);
    // int setBalance(Node* n);
    // Node* findNode(Node*,int);
    // bool remove(int);
    // bool removeItemAt(Node*&,int,Node*);
    // int maxValueAtN(Node*);
    // void balanceAfter(Node*);
    Node* getRootNode();
    bool add(int data);
    bool remove(int data);
    void clear();   
    bool addItemAt(Node* &n,int data,Node*);
    bool removeItemAt(Node* & n, int data,Node*);
    int size();
    int sizeAtN(Node* n);
    int maxValueAtN(Node* n);
    void deleteTree(Node* n);
    Node* findNode(Node* n,int data);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    int height(Node*);
    void balance(Node*);
    int balanceFactor(Node*);
};