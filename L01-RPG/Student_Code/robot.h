#pragma once
#include "fighter.h"
using namespace std;

class Robot: public Fighter
{
	int bonusDamage;
	double energy;
	double maxEnergy;
public:
	void reset();
	virtual bool useAbility();
	virtual int getDamage();
	int getEnergy(){return energy;}
	virtual void regenerate();
	virtual void takeDamage(int d);
	Robot(string n, string t, int mhp, int st, int sp, int m):
		Fighter(n,t,mhp,st,sp,m)
		{
			energy=2*m;
			maxEnergy=energy;
		}
	Robot():Fighter(){};
	~Robot();
};