// #pragma once
#include "FighterInterface.h"
#include "fighter.h"
#include <string>
using namespace std;


	void Fighter::reset()
	{
		//cout<<this->getName()<<" stats were reset"<<endl;
		speed=ispeed;
		health=maxHealth;
	}
	void Fighter::printInfo()
	{
		cout<<"--------------"<<endl;
		cout << "Name: "<<name << endl;
		cout<<"Type: "<<type<<endl;
		cout << "Health: " <<health<< endl;
		cout<<"Strength: "<<strength<<endl;
		cout<<"Speed: "<<speed<<endl;
		cout<< "Magic: "<<magic<<endl;
		cout<<"--------------"<<endl;

	}
	