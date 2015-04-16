#include "avl.h"
#include <iostream>
#include <stack>

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
	while(!ancestors.empty())
	{
		ancestors.pop();
	}
	if(root==NULL)
	{
		cout<<"ADDED: "<<data<<" AT ROOT"<<endl;
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
	// stack<Node*> ancestors;
	// Node* n=root;
	// while(n!=NULL)
	// {
	// 	if(n->data==data)
	// 	{
	// 		return false;
	// 	}
	// 	else if(data < n->data)
	// 	{
	// 		if(n->left!=NULL)
	// 		{
	// 			Node* newnode=new Node();
	// 			newnode->data=data;
	// 			n->left=newnode;
	// 			break;
	// 		}
	// 		else
	// 		{
	// 			if(n->right!=NULL)
	// 			{
	// 				Node* newNode=new Node();
	// 				newNode->data=data;
	// 				n->right=newNode;
	// 				break;
	// 			}
	// 			ancestors.push(n);
	// 			n=n->left;
	// 		}
	// 	}
	// 	else
	// 	{

	// 		ancestors.push(n);
	// 		n=n->right;
	// 	}
	// }
	
	
}

bool AVL::addItemAt(Node*& n, int data)
{
	if(n==NULL)
	{
		
		Node* node=new Node();
		n=node;
		cout<<"ADDED: "<<data<<" at "<<n<<endl;
		n->right=NULL;
		n->left=NULL;
		//n->parent=parent;
		n->data=data;
		while(!ancestors.empty())
		{
			Node* c=ancestors.top();
			ancestors.pop();
			if(!ancestors.empty())
			{
				Node* p=ancestors.top();
				balance(n,p);
			}
		}
		//balance(parent);
		return true;
	}
	else if(data < n->data)
	{
		ancestors.push(n);
		addItemAt(n->left,data);
	}
	else if(data > n->data)
	{
		ancestors.push(n);
		addItemAt(n->right,data);
	}
	else
		return false;

}
bool AVL::remove(int data)
{
	if(removeItemAt(root,data))
		return true;
	else return false;
}

bool AVL::removeItemAt(Node*& n,int data)
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
			removeItemAt(n->left,n->data);
		}
	}
	else if(data < n->data)
	{
		removeItemAt(n->left,data);
	}
	else 
		removeItemAt(n->right,data);
}


Node* AVL::findNode(Node* n,int data)
{
	if(n==NULL)
	{
		return NULL;
	}
	if(n->data==data)
	{
		return n;
	}
	else if(data < n->data)
	{
		return findNode(n->left,data);
	}
	else
		return findNode(n->right,data);
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
	if(b->right!=NULL)
		c->left=b->right;
	else
		c->left=NULL;
	b->right=c;
	return b;
}
Node* AVL::rotateLeft(Node* a)
{
	cout<<"ROTATE LEFT"<<endl;
	Node* b=a->right;
	if(b->left!=NULL)
		a->right=b->left;
	else
		a->right=NULL;
	b->left=a;
	return b;
}
void AVL::balance(Node* n,Node* p)
{
	cout<<"BALANCING"<<endl;
	if(balanceFactor(n)==2)//left
	{
		cout<<"-----LEFT"<<endl;
		if(balanceFactor(n->left)==1)//left left
		{
			cout<<"------LEFT LEFT"<<endl;
			p=rotateRight(n);
		}
		else//left right
		{
			rotateLeft(n->left);
			p=rotateRight(n);
		}
	}
	else if(balanceFactor(n)==-2)
	{
		if(balanceFactor(n->right)==-1)//right right
		{
			p=rotateLeft(n);
		}
		else//right left
		{
			rotateLeft(n->right);
			p=rotateRight(n);
		}
	}
	else if(n->parent!=NULL)
		return;
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