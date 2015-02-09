// #pragma once
#include "archer.h"
#include <string>

void Archer::reset()
{
	speed=ispeed;
	health=maxHealth;
}

bool Archer::useAbility()
{
	//cout<<this->getName()<<" used Quickstep!"<<endl;
	//cout<<this->getName()<<"'s speed increased by 1."<<endl;
	speed+=1;
	return true;
}
int Archer::getDamage()
{
	//cout<<this->getName()<<" attacked ";	
	return (speed);
}
void Archer::regenerate()
{
	int bhealth=health;
	health+=(strength/6);
	if(health-bhealth==0)
	{
		health+=1;
	}
	if(health>maxHealth)
	{
		health=maxHealth;
	}

	//cout<<this->getName()<<"'s health was restored by "<<
		(health-bhealth)<<endl;
}

void Archer::takeDamage(int damage)
{
	//cout<<this->getName()<<"!"<<endl;
	damage-=(speed/4);
	if(damage<1)
	{
		damage=1;
	}
	//cout<<this->getName()<<" took "<<damage<<" points of damage"<<endl;
	health-=damage;
	if(health<=0)
	{
		//cout<<this->getName()<<" died!"<<endl;
	}
}
Archer::~Archer(){}