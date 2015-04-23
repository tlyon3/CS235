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
	// //cout<<"ROOT: "<<root<<endl;
	// //cout<<"add: "<<data<<endl;
	while(!ancestors.empty())
	{
		ancestors.pop();
	}
	if(root==NULL)
	{
		//cout<<"ADDED: "<<data<<" AT ROOT"<<endl;
		Node* n=new Node(data);
		root=n;
		////cout<<"ADDED "<<data<<" at ROOT: "<<root<<endl;
		return true;
	}
	else if(addItemAt(this->root,data))
	{
		////cout<<"DONE"<<endl;
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
		//cout<<"ADDED: "<<data<<" at "<<n<<endl;
		n->right=NULL;
		n->left=NULL;
		//n->parent=parent;
		n->data=data;
		while(!ancestors.empty())
		{
			Node* n=ancestors.top();
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
	if(findNode(root,data)==NULL)
	{
		//cout<<data<<" doesn't exist in tree"<<endl;
		return false;
	}
	//cout<<"ReMoViNg "<<data<<endl;
	if(removeItemAt(root,data))
	{
		//cout<<"removed " <<data<<endl;
		return true;
	}
	else return false;
}

bool AVL::removeItemAt(Node*& n,int data)
{
	if(n==NULL)
	{
		////cout<<"empty tree"<<endl;
		return false;
	}
	if(data==n->data)
	{
		if(n->left==NULL&&n->right!=NULL)
		{
			//cout<<"single right child"<<endl;
			Node* temp=n;
			if(n!=root)
			{
				Node* p=getParent(root,n->data);
				//cout<<"Parent is: "<<p->data<<endl;
				n=n->right;
				balance(n,p);
			}
			else
				n=n->right;
			delete temp;
			return true;
		}
		else if(n->right==NULL&&n->left!=NULL)
		{
			////cout<<"single left child"<<endl;	
			Node* temp=n;
			if(n!=root)
			{
				Node* p=getParent(root,n->data);
				n=n->left;
				balance(n,p);
			}
			else
				n=n->left;
			delete temp;
			return true;
		}
		else if(n->right==NULL&&n->left==NULL)
		{
			Node* temp=n;
			if(n!=root)
			{
				Node* p=getParent(root,n->data);
				n=n->right;
				balance(n,p);
			}
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
		//cout<<"Does not exist"<<endl;
		return NULL;
	}
	if(n->data==data)
	{
		//cout<<"Found " <<data<<" at "<<n<<endl;
		return n;
	}
	else if(data < n->data)
	{
		//cout<<data<<" smaller than "<<n->data<<endl;
		return findNode(n->left,data);
	}
	else
	{
		//cout<<data<<" larger than "<<n->data<<endl;
		return findNode(n->right,data);
	}
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
	//cout<<"ROTATE RIGHT AT "<<c->data<<endl;
	Node* b=c->left;
	if(b->right!=NULL)
		c->left=b->right;
	else
		c->left=NULL;
	b->right=c;
	if(c==root)
		root=b;
	return b;
}
Node* AVL::rotateLeft(Node* a)
{
	//cout<<"ROTATE LEFT AT "<<a->data<<endl;
	
	Node* b=a->right;
	//cout<<"-----a: "<<a->data<<endl;
	//cout<<"-----b: "<<b->data<<endl;
	//cout<<"-----B = A right: "<<a->right->data<<endl;
	//cout<<"-----a->right is b->left: ";
	if(b->left!=NULL)
	{
		//cout<<b->left->data<<endl;
		a->right=b->left;
	}
	else
	{
		//cout<<"NULL"<<endl;
		a->right=NULL;
	}
	b->left=a;
	//cout<<"-----b->left is a: "<<a->data<<endl;
	//cout<<"-----b->right still ";
	if(b->right!=NULL)
		//cout<<b->right->data<<endl;
	//else
		//cout<<"NULL"<<endl;
	if(a==root)
		root=b;
	//cout<<"-----";
	//cout<<b->nodeInfo()<<endl;
	//cout<<a->nodeInfo()<<endl;
	//cout<<"------";
	return b;
}
void AVL::balance(Node* n,Node* p)
{
	//cout<<"BALANCING"<<endl;
	if(balanceFactor(p)==2)//left
	{
		//cout<<"-----LEFT"<<endl;
		int left=balanceFactor(p->left);
		if(left==1||left==0)//left left
		{
			//cout<<"------LEFT LEFT"<<endl;
			Node* gp=getParent(root,p->data);
			if(gp!=NULL)
			{
				//cout<<"-------------Parent of "<<p->data<<": "<<gp->data<<endl;
				if(p->data < gp->data)
					gp->left=rotateRight(p);
				else
					gp->right=rotateRight(p);
				//cout<<"------DDDD-------Parent of "<<p->data<<": "<<gp->data<<endl;
			}
			else
				rotateRight(p);
		}
		else//left right
		{
			//cout<<"LEFT RIGHT"<<endl;
			p->left=rotateLeft(p->left);
			Node* gp=getParent(root,p->data);
			if(gp!=NULL)
			{
				//cout<<"------------Parent of "<<p->data<<": "<<gp->data<<endl;
				if(p->data < gp->data)
					gp->left=rotateRight(p);
				else
					gp->right=rotateRight(p);
				//cout<<"------DDDD------Parent of "<<p->data<<": "<<gp->data<<endl;

			}
			else 
				rotateRight(p);
		}
	}

	else if(balanceFactor(p)==-2)
	{
		//cout<<"RIGHT"<<endl;
		int right=balanceFactor(p->right);
		if(right==-1||right==0)//right right
		{
			//cout<<"RIGHT RIGHT"<<endl;
			Node* gp=getParent(root,p->data);
			if(gp!=NULL)
			{
				//cout<<"---------Parent of "<<p->data<<": "<<gp->data<<endl;
				if(p->data > gp->data)
					gp->right=rotateLeft(p);
				else
					gp->left=rotateLeft(p);
				//cout<<"----DDDD-----Parent of "<<p->data<<": "<<gp->data<<endl;
			}
			else
				rotateLeft(p);
		}
		else//right left
		{
			//cout<<"RIGHT LEFT"<<endl;
			p->right=rotateRight(p->right);
			Node* gp=getParent(root,p->data);
			if(gp!=NULL)
			{
				//cout<<"Parent of "<<p->data<<": "<<gp->data<<endl;
				if(p->data > gp->data)
					gp->right=rotateLeft(p);
				else
					gp->left=rotateLeft(p);
			}
			else 
				rotateLeft(p);
		}
	}
	else if(p->parent!=NULL)
		return;
	else return;
}
int AVL::balanceFactor(Node* n)
{
	//cout<<"CHECKING BALANCE FACTOR FOR "<<n->data<<endl;
	return height(n->left)-height(n->right);
}
int AVL::height(Node* n)
{
	if(n==NULL)
		return 0;
	else return max(height(n->left),height(n->right))+1;
}

Node* AVL::getParent(Node* t,int data)
{
	if(data==t->data)
		return NULL;
	else
	{
		if((t->left!=NULL&&data==t->left->data)||
			(t->right!=NULL&&data==t->right->data))
		{
			return t;
		}
		else if(data < t->data)
			return getParent(t->left,data);
		else if(data > t->data)
			return getParent(t->right,data);
	}
}
