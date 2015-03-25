#include "bst.h"
#include "node.h"
#include "node.cpp"

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
		cout<<"ADDED "<<data<<" at ROOT: "<<root<<endl;
		return true;
	}
	if(addItemAt(this->root,data))
	{
		cout<<"DONE"<<endl;
		return true;
	}
	else return false;
}

bool BST::addItemAt(Node* & n, int data)
{
	//cout<<"ADDITEMAT: "<<n<<", "<<data<<endl;
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
		if(n->right!=NULL)
		{
			addItemAt(n->right,data);
		}
		else
		{
			n->right=new Node(data);
			cout<<"ADDED "<<data<<" at "<<n->right<<endl;
			return true;
		}

	}
	else if (data > n->item)
	{
		if(n->left!=NULL)
		{
			addItemAt(n->left,data);
		}
		else
		{
			n->left=new Node(data);
			cout<<"ADDED "<<data<<" at "<<n->left<<endl;
			return true;
		}
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
	if(n==NULL)
		return -1;
	int value= n->getData();
	Node* left=n->left;
	if(left!=NULL)
	{
		int leftValue=minValueAtN(left);
		if(leftValue<value)
		{
			value=leftValue;
		}
	}
	Node* right=n->right;
	if(right!=NULL)
	{
		int rightValue = minValueAtN(right);
		if(rightValue<value)
		{
			value=rightValue;
		}
	}
	return value;
}

void BST::clear()
{
	deleteTree(root);
	root=NULL;
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