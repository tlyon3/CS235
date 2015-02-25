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
	//int count;
	Node* tail;
	Node* head;
public:
	Deque():head(NULL),tail(NULL){}

	void print()
	{
		Node* n=head;
		std::cout<<"Deque("<<size()<<"): ";
		while(n!=NULL)
		{
			std::cout<<n->item<<" ";
			n=n->next;
		}
		std::cout<<std::endl;
	}
	int size()
	{
		////std::cout<<"check deque size"<<std::endl;
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
			if(head==NULL)
			{
				tail=n;
				n->next=NULL;
			}
			else
			{
				head->prev=n;
				n->next=head;
			}
			n->item=item;
			head=n;
			n->prev=NULL;
			//std::cout<<"Added '"<<item
			//<<"' to deque."<<std::endl;
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
			{
				head=n;
				n->prev=NULL;
			}
			else
			{
				tail->next=n;
				n->prev=tail;
			}
			n->next=NULL;
			tail=n;
			//std::cout<<"Added '"<<item
			//<<"' to deque."<<std::endl;
			return true;
		}
		else return false;
	}
	ItemType removeLeft()
	{
		if(size()>0)
		{
			Node* n=head;
			ItemType item=n->item;
			if(size()==1)
			{
				head=NULL;
				tail=NULL;
			}
			else
			{
				head->prev=NULL;
				head=n->next;
			}
			delete n;
			//std::cout<<"Removed '"<<item
			//<<"' from deque"<<std::endl;
			return n->item;
		}
		else return -1;
	}
	ItemType removeRight()
	{
		if(size()>0)
		{
			Node* n=tail;
			ItemType item=n->item;
			tail=n->prev;
			if(size()==1)
			{
				head=NULL;
				tail=NULL;
			}
			else
			{
				tail->next=NULL;
			}
			//std::cout<<"Removed '"<<item
			//<<"' from deque"<<std::endl;
			delete n;
			return item;
		}
		else return -1;
	}
	ItemType topLeft()
	{
		if(size()>0)
		{
			return head->item;
		}
		else return -1;
	}
	ItemType topRight()
	{
		if(size()>0)
		{
			return tail->item;
		}
		else return -1;
	}
};