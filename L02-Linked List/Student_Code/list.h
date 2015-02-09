#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>
#include <iostream>
using namespace std;
template<class T>
class List:public LinkedListInterface<T>
{
	struct Node
	{
		T value;
		Node* next;
	};
	//int count;
	Node* head;
	Node* tail;
public:
	List():head(NULL),tail(NULL){}
	~List()
	{
		clear();
	}

	T getTail()
	{
		return tail->value;
	}

	T getHead()
	{
		return head->value;
	}

	void insertHead(T value)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* n=new Node();
		n->value=value;
		
		if(head==NULL)		//is the list empty?
		{
			head=n;
			tail=n;
			n->next=NULL;
		}
		else
		{
			n->next=head;
			head=n;
		}
		//print();
	}
	void print()
	{
		Node* n=head;
		int icount=0;
		while(icount<size())
		{
			cout<<n->value<<", ";
			n=n->next;
			icount++;
		}
		cout<<endl;
	}
	void insertTail(T value)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* n=new Node();
		n->value=value;
		if(tail==NULL)
		{
			head=n;
		}
		else
		{
			tail->next=n;
		}
		n->next=NULL;
		tail=n;
	}

	void insertAfter(T value, T insertionNode)
	{
		if(check_for_duplicate(value))
		{
			return;
		}
		Node* inode=head;
		while(inode!=NULL)
		{
			if(inode->value==insertionNode)
			{
				Node* n=new Node();
				n->value=value;
				if(inode==tail)
				{
					tail=n;
					n->next=NULL;
					inode->next=n;
				}
				else
				{
					n->next=inode->next;
					inode->next=n;
				}
			}
			inode=inode->next;
		}
		
	}
	void remove(T value)
	{	
		if(check_for_duplicate(value))
		{
			Node* current=head;
			Node* prev;
			while(current->value!=value)
			{
				prev=current;
				current=current->next;
			}
			if(current==head)
			{
				head=current->next;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;
			}
			else if(current==tail)
			{
				tail=prev;
				prev->next=NULL;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;				
			}
			else
			{
				prev->next=current->next;
				delete current;
				if(size()==0)
				{
					head=NULL;
					tail=NULL;
				}
				return;
			}
			
		}
		else return;

	}

	void clear()
	{
		while(size()>0)
		{
			Node* n=head;
			//T value=n->value;
			head=head->next;
			//count--;
			delete n;
		}
		head=NULL;
		tail=NULL;
	}

	T at(int index)
	{
		Node* n=head;
		int icount=0;
		if(index<0||index>size()-1)
		{
			throw out_of_range("OUT OF RANGE");
		}
		else
		{
			while(icount<index)
			{
				n=n->next;
				icount++;
			}
			return n->value;
		}
	}

	bool check_for_duplicate(T value)
	{
		Node* n=head;
		while(n!=NULL)
		{
			if(n->value==value)
			{
				return true;
			}
			n=n->next;
		}
		return false;
	}
	int size()
	{
		int listcount=0;
		Node* n=head;
		if(head==NULL)
		{
			return 0;
		}
		while(n!=NULL)
		{
			listcount++;
			n=n->next;
		}
		return listcount;
	}
};