#include "node.h"

Node* Node::getLeftChild()
{
	return left;;
}

Node* Node::getRightChild()
{
	return right;
}

int Node::getHeight()
{
	return height;
}

int Node::getData()
{
	return data;
}

void Node::setHeight(int nheight)
{
	height=nheight;
}

void Node::setData(int ndata)
{
	data=ndata;
}

void Node::setLeftChild(Node* n)
{
	this->left=n;
}

void Node::setRightChild(Node* n)
{
	this->right=n;
}

