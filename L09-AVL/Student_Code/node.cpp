#include "node.h"
#include <iostream>
#include <sstream>

Node* Node::getLeftChild()
{
	return left;;
}

Node* Node::getRightChild()
{
	return right;
}

int Node::getData()
{
	return data;
}
int Node::getHeight()
{
	return height;
}
void Node::setData(int ndata)
{
	data=ndata;
}
// void Node::setHeight(Node* n)
// {
// 	height=height(n);
// }
void Node::setLeftChild(Node* n)
{
	this->left=n;
}

void Node::setRightChild(Node* n)
{
	this->right=n;
}

string Node::nodeInfo()
{
	stringstream str;
	str<<"Node: ";
	str<<this<<endl;
	str<<"	data: "<<data<<endl;
	if(left!=NULL)
	{
		str<<"	left: "<<left->data<<"|"<<left<<endl;
	}
	else
		str<<"	left: NULL"<<endl;
	if(right!=NULL)
	{
		str<<"	right: "<<right->data<<"|"<<right<<endl;
	}
	else 
		str<<"	right: NULL"<<endl;
	if(parent!=NULL)
	{
		str<<"	parent: "<<parent->data<<"|"<<parent<<endl;
	}
	else
		str<<"	parent: NULL"<<endl;
	return str.str();

}

