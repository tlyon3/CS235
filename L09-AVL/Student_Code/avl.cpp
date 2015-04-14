#include "avl.h"

Node* AVL::getRootNode()
{
	return root;
}

bool AVL::add(int data)
{
	if(root==NULL)
	{
		Node* n=new Node(data);
		root=n;
		n->setHeight(0);
		//BALANCE
		return true;
	}
	else if(addItemAt(root,data))
	{
		//BALANCE
		return true;
	}
	else return false;
}

Node* AVL::findMinNode(Node* n)
{
	return n->left?findMinNode(n->left):n;
}
Node* AVL::removeMinNode(Node* n)
{
	if(n->left==0)
		return n->right;
	n->left=removeMinNode(n->left);
	return balance(n);
}
bool AVL::addItemAt(Node*& n, int data)
{
	if(n==NULL)
	{
		Node* node=new Node(data,NULL,NULL);
		n=node;
		balance(n);
		return true;
	}
	else if(data < n->getData())
	{
		Node* l=n->getLeftChild();
		addItemAt(l,data);
	}
	else if(data > n->getData())
	{
		Node* r=n->getRightChild();
		addItemAt(r,data);
	}
	else
		return false;
}

bool AVL::remove(int data)
{
	if(removeItemAt(root,data))
	{
		//BALANCE
		return true;
	}
	else return false;	
}

Node* AVL::removeItemAt(Node*& n, int data)
{
	if(!n)
		return NULL;
	if(data < n->data)
		n->left=removeItemAt(n->left,data);
	else if(data>n->data)
		n->right=removeItemAt(n->right,data);
	else
	{
		Node* q = n->left;
		Node* r = n->right;
		delete n;
		if(!r) return q;
		Node* min=findMinNode(root);
		min->right=removeMinNode(root);
		min->left=q;
		return balance(min);
	}
	return balance(n);
}

Node* AVL::findNode(Node* n,int data)
{
	if(n==NULL)
	{
		return NULL;
	}
	else if(n->getData()==data)
	{
		return n;
	}
	else if(data<n->getData())
	{
		findNode(n->getLeftChild(),data);
	}
	else if (data>n->getData())
	{
		findNode(n->getRightChild(),data);
	}
	else return NULL;
}

int AVL::maxValueAtN(Node* n)
{
	if(n==NULL)
		return -1;
	int value= n->getData();
	Node* left=n->getLeftChild();
	if(left!=NULL)
	{
		int leftValue=maxValueAtN(left);
		if(leftValue>value)
		{
			value=leftValue;
		}
	}
	Node* right=n->getRightChild();
	if(right!=NULL)
	{
		int rightValue = maxValueAtN(right);
		if(rightValue>value)
		{
			value=rightValue;
		}
	}
	return value;
}

Node* AVL::rotateRight(Node* n)
{
	Node* p=n->getRightChild();
	p->setLeftChild(n->getRightChild());
	n->setRightChild(p);
	fixHeight(p);
	fixHeight(n);
	return n;

}

Node* AVL::rotateLeft(Node* n)
{
	Node* p = n->right;
	n->right=p->left;
	p->left=n;
	fixHeight(n);
	fixHeight(p);
	return p;
}

void AVL::fixHeight(Node* n)
{
	int hl = n->left->height;
	int hr = n->right->height;
	n->height= (hl>hr ? hl:hr) +1;
}

Node* AVL::balance(Node* p)
{
	fixHeight(p);
	if(balanceFactor(p)==2)
	{
		if(balanceFactor(p->right)<0)
			p->right=rotateRight(p->right);
		return rotateLeft(p);
	}
	if(balanceFactor(p)==-2)
	{
		if(balanceFactor(p->left)>0)
			p->left=rotateLeft(p->left);
		return rotateRight(p);
	}
	return p;
}

int AVL::balanceFactor(Node* n)
{
	return (n->right->height - n->left->height);
}