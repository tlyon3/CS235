 
#include <sstream>
#include <iterator>
#include <cassert>
#include "arena.h"
#include "fighter.h"
#include "archer.h"
#include "robot.h"
#include "cleric.h"

bool Arena::addFighter(string info)
{	
	istringstream ss(info);					//Code to parse the string into separate values
	istream_iterator<string> begin(ss), end;
	vector<string> words(begin,end);
	if(words.size()!=6)
	{
		//cout<<"ERROR CREATING FIGHTER: Input not in right format"<<endl;
		//cout<<"		-Incorrect amout of fields. Should be 6"<<endl;
		return false;
	}
	assert(words.size() >= 6);
	int n=words.size()-1;
	if(words[1]!="A")
	{
		if(words[1]!="C")
		{
			if(words[1]!="R")
			{
				//cout<<"ERROR CREATING FIGHTER: Input not in right format"<<endl;
				//cout<<"		-Type of fighter is not correct"<<endl;
				return false;
			}
		}
	}
	for(int i=0;i<fighterList.size();i++)
	{
		if(words[0]==fighterList[i]->getName())
		{
			//cout<< "ERROR CREATING FIGHTER: Fighter with the name "<<words[0]
			//<<" already exists!"<<endl;

			return false;
		}
	}
	double mhp;
	double st;
	double m;
	double sp;
	try
	{
		mhp=stod(words[2]);
		if(mhp-(int)mhp>0)
		{
			//cout<<"ERROR CREATING FIGHTER: INVALID INPUT"<<endl;
			//cout<<"		-Value for HP cannot have decimal."<<endl;
			return false;
		}
		if(mhp<=0)
		{
			//cout<<"ERROR CREATING FIGHTER: Invalid input"<<endl;
			//cout<<"		-The value for HP is not positive"<<endl;
			return false;
		}
	}
	catch(...) 
	{
		//cout<<"ERROR CREATING FIGHTER: Input not in right format"<<endl;
		//cout<<"		-The value of HP is not an integer"<<endl;
		return false;
	}
	try
	{
		st=stod(words[3]);
		if(st-(int)st>0)
		{
			//cout<<"ERROR CREATING FIGHTER: INVALID INPUT"<<endl;
			//cout<<"		-Value for strength cannot have decimal."<<endl;
			return false;
		}
		if(st<=0)
		{
			//cout<<"ERROR CREATING FIGHTER: Invalid input"<<endl;
			//cout<<"		-The value for Strength is not positive"<<endl;
			return false;
		}
	}
	catch(...)
	{
		//cout<<"ERROR CREATING FIGHTER: Input not in right format."<<endl;
		//cout<<"		-The value of Strength is not an integer"<<endl;
		return false;
	}
	try
	{
		sp=stod(words[4]);
		if(sp-(int)sp>0)
		{
			//cout<<"ERROR CREATING FIGHTER: INVALID INPUT"<<endl;
			//cout<<"		-Value for speed cannot have decimal."<<endl;
			return false;
		}
		if(sp<=0)
		{
			//cout<<"ERROR CREATING FIGHTER: Invalid input"<<endl;
			//cout<<"		-The value for Speed is not positive"<<endl;
			return false;
		}
	}
	catch(...)
	{
		//cout<<"ERROR CREATING FIGHTER: Input not in right format."<<endl;
		//cout<<"		-The value of Speed is not an ineger."<<endl;
		return false;
	}
	try
	{
		m=stod(words[5]);
		if(m-(int)m>0)
		{
			//cout<<"ERROR CREATING FIGHTER: INVALID INPUT"<<endl;
			//cout<<"		-Value for magic cannot have decimal."<<endl;
			return false;
		}
		if(m<=0)
		{
			//cout<<"ERROR CREATING FIGHTER: Invalid input"<<endl;
			//cout<<"		-The value for Mana is not positive"<<endl;
			return false;
		}
	}
	catch(...)
	{
		//cout<<"ERROR CREATING FIGHTER: Input not in right format."<<endl;
		//cout<<"		-The value of Speed is not an integer."<<endl;
		return false;
	}

	if (words[1]=="A")
	{
		Fighter* fighter=new Archer(words[0],words[1],mhp,st,sp,m);
		fighterList.push_back(fighter);
		//cout<<"New archer "<<words[0]<<" joined the fight!"<<endl;
		return true;
	}
	else if(words[1]=="R")
	{
		Fighter* fighter=new Robot(words[0],words[1],mhp,st,sp,m);
		fighterList.push_back(fighter);
		//cout<<"New robot "<<words[0]<<" joined the fight!"<<endl;
		return true;
	}
	else if(words[1]=="C")
	{
		Fighter* fighter=new Cleric(words[0],words[1],mhp,st,sp,m);
		fighterList.push_back(fighter);
		//cout<< "New cleric "<<words[0]<<" joined the fight!"<<endl;
		return true;
	}
	else //should never get this error
	{
		//cout<<"ERROR. Was the entry in the correct format?"<<endl;
		return false;
	}

}

bool Arena::removeFighter(string fname)
{
	for(int i=0;i<fighterList.size();i++)
	{
		if(fighterList[i]->getName()==fname)
		{
			fighterList.erase(fighterList.begin()+(i));
			return true;
		}
	}
	return false;
}
FighterInterface* Arena::getFighter(string fname)
{
	for(int i=0;i<fighterList.size();i++)
	{
		if(fighterList[i]->getName()==fname)
		{
			return fighterList[i];
		}
	}
	//cout<<"No fighter with the name "<<fname
	//<<" was found"<<endl;
	return NULL;
}
int Arena::getSize()
{
	return fighterList.size();
}
void Arena::printNames()
{
	//cout<<"Fighters in arena: ";
	for(int i=0;i<this->fighterList.size();i++)
	{
		//cout<<this->fighterList[i]->getName()<<", ";
	}
	//cout<<endl;
}

