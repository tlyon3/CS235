#pragma once
#include <cstddef>
#include <iostream>
template <typename ItemType>

class Queue
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
	Queue():count(0),head(NULL),tail(NULL){}
	void print()
	{
		Node* n=head;
		std::cout<<"Queue("<<count<<"): ";
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

	int size() const
	{
		return count;
	}

	bool append(ItemType item)
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
				tail->next=n;
			n->next=NULL;
			tail=n;
			count++;
			//std::cout<<"Added '"<<item
			//<<"' to queue."<<std::endl;
			return true;
		}
		else return false;
	}

	ItemType remove()
	{
		if(count>0)
		{
			Node* n=head;
			if(count==1)
			{
				head=NULL;
				tail=NULL;
			}
			else
			{
				head=n->next;
				tail->prev=NULL;
			}
			delete n;
			count--;
			//std::cout<<"Removed '"<<n->item
			//<<"' from queue."<<std::endl;
			return n->item;
		}
		else return -1;
	}

	int size()
	{
		return count;
	}

	ItemType top()
	{
		if(size()>0)
		{
			return head->item;
		}
		else return -1;
	}

};