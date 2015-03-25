#include "bst.h"
#include "node.h"
//#include "node.cpp"

Node* BST::getRootNode()
{
	return this->root;
}

bool BST::add(int data)
{
	// cout<<"ROOT: "<<root<<endl;
	// cout<<"add: "<<data<<endl;
	if(root==NULL)
	{
		Node* n=new Node(data);
		root=n;
		//cout<<"ADDED "<<data<<" at ROOT: "<<root<<endl;
		return true;
	}
	else if(addItemAt(this->root,data))
	{
		//cout<<"DONE"<<endl;
		return true;
	}
	else return false;
}

bool BST::addItemAt(Node* &n, int data)
{
	if(n==NULL)
	{
		Node* node=new Node(data,NULL,NULL);
		n=node;
		return true;
	}
	else if(data < n->item)
	{
		addItemAt(n->left,data);
	}
	else if(data > n->item)
		addItemAt(n->right,data);
	else
		return false;

}
bool BST::remove(int data)
{
	if(removeItemAt(root,data))
		return true;
	else return false;
}

bool BST::removeItemAt(Node*& n,int data)
{
	if(n==NULL)
	{
		//cout<<"empty tree"<<endl;
		return false;
	}
	if(data==n->item)
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
			n->item=maxValueAtN(n->left);//*max value in left*
			removeItemAt(n->left,n->item);
		}
	}
	else if(data < n->item)
	{
		removeItemAt(n->left,data);
	}
	else 
		removeItemAt(n->right,data);
}


Node* BST::findNode(Node* n,int data)
{
	if(n==NULL)
	{
		return NULL;
	}
	else if(n->item==data)
	{
		return n;
	}
	else if(data<n->item)
	{
		findNode(n->left,data);
	}
	else if (data>n->item)
	{
		findNode(n->right,data);
	}
	else return NULL;
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
int BST::maxValueAtN(Node* n)
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

void BST::clear()
{
	while(root!=NULL)
	{
		remove(root->item);
	}
}

void BST::deleteTree(Node* n)
{
	if(n==NULL)
		return;
	deleteTree(n->left);
	deleteTree(n->right);
	n=NULL;
	free(n);
}