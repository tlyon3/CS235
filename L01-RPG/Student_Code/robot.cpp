// #pragma once
#include "robot.h"
#include <tgmath.h>

void Robot::reset()
{
	energy=maxEnergy;
	health=maxHealth;
	bonusDamage=0;
}
bool Robot::useAbility()
{
	if(this->getEnergy()<ROBOT_ABILITY_COST)
	{
		return false;
	}
	else if (this->getEnergy()>=ROBOT_ABILITY_COST)
	{	
		double ratio=energy/maxEnergy;
		//cout<<this->getName()<<" used Shockwave Punch!"<<endl;
		bonusDamage += (this->getStrength()*(pow(ratio,4)));
		energy-=ROBOT_ABILITY_COST;
		return true;
	}
	else return false;
}

int Robot::getDamage()
{
	int damage=this->getStrength()+bonusDamage;
	bonusDamage=0;
	//cout<<this->getName()<<" attacked ";
	return (damage);

}

void Robot::takeDamage(int damage)
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

void Robot::regenerate()
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
Robot::~Robot(){}