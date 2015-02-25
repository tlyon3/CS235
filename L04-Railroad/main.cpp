#include "Factory.cpp"
#include "station.cpp"
using namespace std;
int main()
{
	Station myStation;
	myStation.addToStation(2);
	myStation.addToDequeLeft();
	myStation.removeFromDequeRight();
	myStation.removeFromStation();
	for(int i=1;i<10;i++)
	{
		myStation.addToStation(i);
		myStation.addToDequeLeft();

	}
	myStation.addToStation(5);
	myStation.addToDequeLeft();

	myStation.printAll();
	for(int i=1;i<5;i++)
	{
		myStation.removeFromDequeRight();
		myStation.addToStack();
		myStation.removeFromDequeRight();
		myStation.addToQueue();
		myStation.printAll();
	}
	myStation.removeFromStack();
	myStation.addToQueue();
	myStation.removeFromStack();
	myStation.removeFromStation();
	myStation.removeFromQueue();
	myStation.removeFromStation();
	myStation.removeFromDequeRight();
	myStation.printAll();
}