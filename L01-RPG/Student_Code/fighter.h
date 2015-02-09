#pragma once
#include "FighterInterface.h"
 

class Fighter : public FighterInterface
{
protected:
	string name;
	string type;
	int maxHealth;	
	int health;
	int ispeed;
	int speed;
	int magic;
	int maxMagic;
	int strength;	
public:
	Fighter(string n, string t, int mhp, int st, int sp, int m)
	{
		name=n;
		type=t;
		health=mhp;
		maxMagic=m;
		maxHealth=mhp;
		speed=sp;
		strength=st;
		ispeed=sp;
		magic=m;
	}
	Fighter();
	~Fighter(){};
	string getName() {return name;}
	int getCurrentHP() {return health;}
	int getSpeed() {return speed;}
	int getMagic() {return magic;}
	int getMaximumHP() {return maxHealth;}
	int getStrength() {return strength;}
	virtual int getDamage()=0;
	virtual void regenerate()=0;
	virtual void takeDamage(int damage)=0;
	virtual bool useAbility()=0;
	virtual void reset();
	void printInfo();
	
};