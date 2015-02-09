#include "Factory.cpp"
#include "arena.cpp"
#include "fighter.cpp"
#include "cleric.cpp"
#include "archer.cpp"
#include "robot.cpp"
using namespace std;

int main()
{
	Arena a;
	a.addFighter("CKKnuckrolls A 50 5 2 10");
	a.addFighter("Sg_Bourquez R 10000 20 10 10");
	a.addFighter("CKKnuckrolls R 100 12 10 1");
	a.addFighter("Acrum C 50 8 10 100");
	a.addFighter("asdn t 20 19 10 2");
	a.addFighter("asdfa A 10 10 10 10 10");
	a.addFighter("asdf A 100 2 10 -10");
	cout<<"Number of fighters in arena: "<<
	a.getSize()<< endl;
	a.printNames();
	a.addFighter("adns A d 2 2");
	a.addFighter("asdd A 10 10.5 2 2");
	a.addFighter("asdd A 10 2 10.5 2");
	a.addFighter("asdd A 10 2 2 10.5");
	a.addFighter("addsfa A 10.5 10 10 10");
	//cout<<a.getFighter("addsfa")->getCurrentHP()<<endl;
	//a.fighterList[1]->printInfo();
	a.fighterList[0]->takeDamage(a.fighterList[1]->getDamage());
	a.fighterList[1]->takeDamage(a.fighterList[0]->getDamage());
	a.fighterList[1]->useAbility();
	//a.fighterList[1]->printInfo();
	a.fighterList[1]->regenerate();
	a.fighterList[2]->takeDamage(a.fighterList[1]->getDamage());
	a.fighterList[2]->regenerate();
	a.fighterList[2]->useAbility();
	a.getFighter("CKKnuckrolls")->takeDamage(
		a.getFighter("Acrum")->getDamage());
	//a.fighterList[2]->printInfo();
	a.fighterList[2]->useAbility();
	//a.fighterList[2]->printInfo();
	a.fighterList[0]->useAbility();
	a.fighterList[1]->useAbility();
	a.fighterList[1]->useAbility();
	a.fighterList[1]->useAbility();
	//a.fighterList[1]->printInfo();
	a.fighterList[0]->reset();
	//a.fighterList[0]->printInfo();
	a.fighterList[0]->takeDamage(a.fighterList[1]->getDamage());
	a.fighterList[1]->takeDamage(a.fighterList[0]->getDamage());
}
