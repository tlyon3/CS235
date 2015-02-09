// #pragma once
#include "cleric.h"

void Cleric::reset()
{
	health=maxHealth;
	mana=maxMana;
}
bool Cleric::useAbility()
{
	if(mana>=CLERIC_ABILITY_COST)
	{
		//cout<<mana<<endl;
		int bhealth=health;
		//cout<<health<<endl;
		health+=(magic/3);
		//cout<<this->getName()<<" used Healing Light!"<<endl;
		if(health>maxHealth)
		{
			health=maxHealth;
		}
		//cout<<this->getName()<<"'s health was restored by "<<
		(health-bhealth)<<endl;
		////cout<<health<<endl;
		mana-=CLERIC_ABILITY_COST;
		return true;
	}
	else return false;
}
int Cleric::getDamage()
{
	//cout<<this->getName()<<" attacked ";
	////cout<<" Did "<<this->getMagic()<<" points of damage."<<endl;
	return magic;
}
void Cleric::regenerate()
{
	//cout<<this->getName()<<" used regenerate!"<<endl;
	int bhealth=health;
	int bmana=mana;
	////cout<<strength<<endl;
	////cout<<health<<endl;
	health+=(strength/6);
	if(health-bhealth==0)
	{
		health+=1;
	}
	if(health>maxHealth)
	{
		health=maxHealth;
	}
	mana+=(magic/5);
	if(mana-bmana==0)
	{
		mana+=1;
	}
	if(mana>maxMana)
	{
		mana=maxMana;
	}
	//cout<<this->getName()<<"'s health was restored by "<<
		(health-bhealth)<<endl;
	//cout<<this->getName()<<"'s mana was restored by "<<
		(mana-bmana)<<endl;
}
void Cleric::takeDamage(int damage)
{
	//cout<<this->getName()<<"!"<<endl;
	damage-=(this->getSpeed()/4);
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
Cleric::~Cleric(){}
