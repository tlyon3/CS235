#pragma once
#include "fighter.h"
using namespace std;

class Cleric : public Fighter
{
public:
	bool useAbility();
	int getDamage();
	int mana;
	int maxMana;
	void reset();
	int getMana(){return mana;}
	void regenerate();
	void takeDamage(int damage);
	Cleric(string n, string t, int mhp, int st, int sp, int m):
	Fighter(n,t,mhp,st,sp,m)
	{
		mana=5*magic;
		maxMana=mana;
	};
	Cleric():Fighter(){};
	~Cleric();
};