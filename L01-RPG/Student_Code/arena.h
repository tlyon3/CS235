#pragma once 
#include "ArenaInterface.h"


class Arena: public ArenaInterface
{
public:
	Arena():ArenaInterface(){}
	~Arena(){};
	vector<FighterInterface*> fighterList;
	bool removeFighter(string name);
	bool addFighter(string info);
	int getSize();
	void printNames();
	FighterInterface* getFighter(string fname);
};