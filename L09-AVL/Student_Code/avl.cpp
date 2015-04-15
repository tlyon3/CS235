#include "avl.h"
#include <iostream>

#include "AVL.h"
#include "node.h"
//#include "node.cpp"

Node* AVL::getRootNode()
{
	return this->root;
}

bool AVL::add(int data)
{
	// cout<<"ROOT: "<<root<<endl;
	// cout<<"add: "<<data<<endl;
	if(root==NULL)
	{
		Node* n=new Node(data);
		root=n;
		n->parent=NULL;
		//cout<<"ADDED "<<data<<" at ROOT: "<<root<<endl;
		return true;
	}
	else if(addItemAt(this->root,data,NULL))
	{
		//cout<<"DONE"<<endl;
		return true;
	}
	else return false;
}

bool AVL::addItemAt(Node*& n, int data,Node* parent)
{
	if(n==NULL)
	{
		Node* node=new Node();
		n=node;
		n->right=NULL;
		n->left=NULL;
		n->parent=parent;
		n->data=data;
		balance(parent);
		return true;
	}
	else if(data < n->data)
	{
		addItemAt(n->left,data,n);
	}
	else if(data > n->data)
		addItemAt(n->right,data,n);
	else
		return false;

}
bool AVL::remove(int data)
{
	if(removeItemAt(root,data,NULL))
		return true;
	else return false;
}

bool AVL::removeItemAt(Node*& n,int data,Node* parent)
{
	if(n==NULL)
	{
		//cout<<"empty tree"<<endl;
		return false;
	}
	if(data==n->data)
	{
		if(n->left==NULL&&n->right!=NULL)
		{
			//cout<<"single right child"<<endl;
			Node* temp=n;
			n=n->right;
			delete temp;
			return true;
		}
		else if(n->right==NULL&&n->left!=NULL)
		{
			//cout<<"single left child"<<endl;
			Node* temp=n;
			n=n->left;
			delete temp;
			return true;
		}
		else if(n->right==NULL&&n->left==NULL)
		{
			Node* temp=n;
			n=NULL;
			delete temp;
			return true;

		}
		else
		{
			n->data=maxValueAtN(n->left);//*max value in left*
			removeItemAt(n->left,n->data,n);
		}
	}
	else if(data < n->data)
	{
		removeItemAt(n->left,data,n);
	}
	else 
		removeItemAt(n->right,data,n);
}


Node* AVL::findNode(Node* n,int data)
{
	if(n==NULL)
	{
		return NULL;
	}
	else if(n->data==data)
	{
		return n;
	}
	else if(data<n->data)
	{
		findNode(n->left,data);
	}
	else if (data>n->data)
	{
		findNode(n->right,data);
	}
	else return NULL;
}

int AVL::size()
{
	if(root==NULL)
		return 0;
	else return sizeAtN(root);
}

int AVL::sizeAtN(Node* n)
{
	if(n==NULL)
	{
		return 0;
	}
	else 
	{
		return(sizeAtN(n->left)+1+sizeAtN(n->right));
	}

}
int AVL::maxValueAtN(Node* n)
{
	if(n==NULL)
		return -1;
	int value= n->getData();
	Node* left=n->left;
	if(left!=NULL)
	{
		int leftValue=maxValueAtN(left);
		if(leftValue>value)
		{
			value=leftValue;
		}
	}
	Node* right=n->right;
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

void AVL::clear()
{
	while(root!=NULL)
	{
		remove(root->data);
	}
}

void AVL::deleteTree(Node* n)
{
	if(n==NULL)
		return;
	deleteTree(n->left);
	deleteTree(n->right);
	n=NULL;
	free(n);
}

Node* AVL::rotateRight(Node* c)
{
	cout<<"ROTATE RIGHT"<<endl;
	Node* b=c->left;
	if(c->right!=NULL)
		b->left=c->right;
	else b->left=NULL;
	b->right=c;
	if(b->left!=NULL)
		b->left->parent=b;
	if(b->right!=NULL)
		b->right->parent=b;
	if(c->parent!=NULL)
		b->parent=c->parent;
	else 
	{
		b->parent=NULL;
		root=b;
	}
	c->parent=b;
	return b;
}
Node* AVL::rotateLeft(Node* n)
{
	cout<<"ROTATE LEFT"<<endl;
	Node* q=n->right;
	if(q->left!=NULL)
		n->right=q->left;
	else n->right=NULL;
	q->left=n;
	if(q->left!=NULL)
		q->left->parent=q;
	if(q->right!=NULL)
		q->right->parent=q;
	if(n->parent!=NULL)
		q->parent=n->parent;
	else
	{
		q->parent=NULL;
		root=q;
	}
	n->parent=q;
	return q;
}
void AVL::balance(Node* n)
{
	if(balanceFactor(n)==2)//left
	{
		if(balanceFactor(n->left)==1)//left left
		{
			rotateRight(n);
		}
		else//left right
		{
			rotateLeft(n->left);
			rotateRight(n);
		}
	}
	else if(balanceFactor(n)==-2)
	{
		if(balanceFactor(n->right)==-1)//right right
		{
			rotateLeft(n);
		}
		else//right left
		{
			rotateLeft(n->right);
			rotateRight(n);
		}
	}
	else if(n->parent!=NULL)
		balance(n->parent);
	else return;
}
int AVL::balanceFactor(Node* n)
{
	return height(n->left)-height(n->right);
}
int AVL::height(Node* n)
{
	if(n==NULL)
		return 0;
	else return max(height(n->left),height(n->right))+1;
}