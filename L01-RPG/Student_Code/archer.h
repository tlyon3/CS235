#pragma once
#include "fighter.h" 
using namespace std;

class Archer: public Fighter
{
public:
	void reset();
	bool useAbility();
	int getDamage();
	void regenerate();
	void takeDamage(int damage);
	Archer(string n, string t, int mhp, int st, int sp, int m):
	Fighter(n,t,mhp,st,sp,m){};
	Archer():Fighter(){};
	~Archer();
};