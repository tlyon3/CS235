#include "bst.h"

Node* BST::getRootNode()
{
	return this->root;
}

bool BST::add(int data)
{
	if(root==NULL)
	{
		Node* n=new Node();
		root=n;
		return true;
	}
	if(addItemAt(this->root,data))
		return true;
	else return false;
}

bool addItemAt(Node* & n, int data)
{
	if(n->item==data)
		return false;
	else if(n==NULL)
	{
		Node* node = new Node();
		n->item=data;
		n=node;
		return true;
	}
	else if(data<n->item)
	{
		addItemAt(n->right,data);
	}
	else if (data > n->item)
	{
		addItemAt(n->left,data);
	}
	else return false;
}

bool BST::remove(int data)
{
	if(removeItemAt(this->root, data))
		return true;
	else return false;
}


bool BST::removeItemAt(Node* & n, int data)
{
	if(n==NULL)
	{
		return false;
	}
	else if(data<n->item)
	{
		removeItemAt(n->right,data);
	}
	else if(data>n->item)
		removeItemAt(n->left,data);
	else 
	{
		if(n->left==NULL)
		{
			Node* t=n;
			n=n->right;
			delete t;
			return true;
		}
		else if(n->right==NULL)
		{
			Node* t=n;
			n=n->left;
			delete t;
			return true;
		}
		else
		{
			n->item=minValueAtN(n->right);
			removeItemAt(n,n->item);
			return true;
		}
	}
	
}

int BST::size()
{
	if(root==NULL)
		return 0;
	else return sizeAtN(root);
}

int BST::sizeAtN(Node* n)
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
int BST::minValueAtN(Node* n)
{
	Node* current=n;
	while(n!=NULL)
	{
		current=current->getLeftChild();
	}
	return current->getData();
}

void BST::clear()
{
	Node* n;
	int count=size();
	while(count)
	{
		delete n;
		count--;
	}
	root=NULL;
}