#pragma once
#include <cstddef>
#include <iostream>
template <typename ItemType>

class Deque
{
private:
	struct Node
	{
		ItemType item;
		Node* next;
		Node* prev;
	};
	int count;
	Node* tail;
	Node* head;
public:
	Deque():count(0),head(NULL),tail(NULL){}

	void print()
	{
		Node* n=head;
		std::cout<<"Deque("<<count<<"): ";
		while(n!=NULL)
		{
			std::cout<<n->item<<" ";
			n=n->next;
		}
		std::cout<<std::endl;
	}
	int size()
	{
		return count;
	}
	bool doesExist(ItemType item)
	{
		Node* n=head;
		while(n!=NULL)
		{
			if(n->item==item)
			{
				return true;
			}
			else n=n->next;
		}
		return false;
	}
	bool appendLeft(ItemType item)
	{
		if(!doesExist(item)&&item!=-1)
		{
			Node* n=new Node();
			n->item=item;
			if(head==NULL)
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
			count++;
			std::cout<<"Added '"<<item
			<<"' to deque."<<std::endl;
			return true;
		}
		else return false;
	}

	bool appendRight(ItemType item)
	{
		if(!doesExist(item)&&item!=-1)
		{
			Node* n=new Node();
			n->item = item;
			if(tail==NULL)
				head=n;
			else
				tail->next = n;
			n->next = NULL;
			n->prev=tail;
			tail=n;
			count++;
			std::cout<<"Added '"<<item
			<<"' to deque."<<std::endl;
			return true;
		}
		else return false;
	}
	ItemType removeLeft()
	{
		if(count>0)
		{
			Node* n=head;
			ItemType item=n->item;
			head=n->next;
			head->prev=NULL;
			delete n;
			count--;
			std::cout<<"Removed '"<<item
			<<"' from deque"<<std::endl;
			return n->item;
		}
		else return -1;
	}
	ItemType removeRight()
	{
		if(count>0)
		{
			Node* n=tail;
			ItemType item=n->item;
			tail=n->prev;
			tail->next=NULL;
			count--;
			delete n;
			return item;
		}
		else return -1;
	}
	ItemType topLeft()
	{
		return head->item;
	}
	ItemType topRight()
	{
		return tail->item;
	}
};