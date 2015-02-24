#pragma once
#include <cstddef>
#include <iostream>
template <typename ItemType>

class Stack
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
	ItemType top()
	{
		return tail->item;
	}

	void print()
	{
		Node* n=head;
		std::cout<<"Stack("<<size()<<"): ";
		while(n!=NULL)
		{
			std::cout<<n->item<<" ";
			n=n->next;
		}
		std::cout<<std::endl;
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

	Stack() :head(NULL),tail(NULL){}


	bool push(const ItemType& item)
	{
		if(!doesExist(item)&&item!=-1)
		{
			Node* n=new Node();
			n->item=item;
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
			//count++;
			// std::cout<<"Added '"<<item
			// <<"' to stack."<<std::endl;
			return true;
		}
		else return false;
	}

	ItemType pop()
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
				tail->next=NULL;
			delete n;
			// std::cout<<"Removed '"<<item
			// <<"' from stack"<<std::endl;
			return item;
		}
		else return -1;
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
	// ~Stack()
	// {
	// 	while(size()>0)
	// 	{
	// 		pop();
	// 	}
	// }
};