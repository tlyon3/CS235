#include "station.h"
#include <iostream>
Station::Station()
{
	currentCar=-1;
}

void Station::printAll()
{
	std::cout<<"-----------------"<<std::endl;
	stationDeque.print();
	stationStack.print();
	stationQueue.print();
	std::cout<<"Current car: "<<currentCar<<std::endl;
	std::cout<<"-----------------"<<std::endl;
}
bool Station::addToStation(int car)
{
	if(stationStack.doesExist(car)||
		stationDeque.doesExist(car)||
		stationQueue.doesExist(car))
	{
		return false;
	}
	if(car<=0)
	{
		return false;
	}
	if(currentCar==-1)
	{
		currentCar=car;
		return true;
	}
	else return false;
}
int Station::showCurrentCar()
{
	return currentCar;
}
bool Station::removeFromStation()
{
	if(currentCar!=-1)
	{
		std::cout<<"Removed '"<<currentCar
		<<"' from station"<<std::endl;
		currentCar=-1;
		return true;
	}
	else return false;
}
bool Station::addToStack()
{
	if(stationStack.push(currentCar))
	{
		currentCar=-1;
		return true;
	}
	else return false;
}
bool Station::removeFromStack()
{
	if(currentCar==-1&&stationStack.size()>0)
	{
		currentCar=stationStack.pop();
		return true;
	}	
	else return false;
}
int Station::showTopOfStack()
{
	return stationStack.top();
}
int Station::showSizeOfStack()
{
	return stationStack.size();
}
bool Station::addToQueue()
{
	if(stationQueue.append(currentCar))
	{
		currentCar=-1;
		return true;
	}
	else return false;
}
bool Station::removeFromQueue()
{
	if(currentCar==-1&&stationQueue.size()>0)
	{
		currentCar=stationQueue.remove();
		return true;
	}
	else return false;
}
int Station::showTopOfQueue()
{
	return stationQueue.top();
}
int Station::showSizeOfQueue()
{
	return stationQueue.size();
}
bool Station::addToDequeLeft()
{
	if(stationDeque.appendLeft(currentCar))
	{
		currentCar=-1;
		return true;
	}
	else return false;
}
bool Station::addToDequeRight()
{
	if(stationDeque.appendRight(currentCar))
	{
		currentCar=-1;
		return true;
	}
	return false;
}
bool Station::removeFromDequeLeft()
{
	if(currentCar==-1&&stationDeque.size()>0)
	{
		currentCar=stationDeque.removeLeft();
		return true;
	}
	else return false;
}
bool Station::removeFromDequeRight()
{
	if(currentCar==-1&&stationDeque.size()>0)
	{
		currentCar=stationDeque.removeRight();
		return true;
	}
	else return false;
}
int Station::showTopOfDequeLeft()
{
	return stationDeque.topLeft();
}
int Station::showTopOfDequeRight()
{
	return stationDeque.topRight();
}
int Station::showSizeOfDeque()
{
	return stationDeque.size();
}