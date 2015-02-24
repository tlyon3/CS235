#include "Factory.cpp"
#include "station.cpp"
using namespace std;
int main()
{
	Station myStation;
	for(int i=1;i<10;i++)
	{
		myStation.addToStation(i);
		myStation.addToDequeLeft();

	}
	myStation.addToStation(5);
	myStation.addToDequeLeft();

	myStation.printAll();
	for(int i=1;i<10;i++)
	{
		myStation.removeFromDequeRight();
		myStation.removeFromStation();
		myStation.printAll();
	}
	myStation.printAll();
}