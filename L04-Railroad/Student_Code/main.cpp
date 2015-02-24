#include "Factory.cpp"
#include "station.cpp"
using namespace std;
int main()
{
	Station myStation;
	for(int i=0;i<10;i++)
	{
		myStation.addToStation(i);
		myStation.addToDequeLeft();

	}
	myStation.printAll();
	for(int i=0;i<10;i++)
	{
		myStation.removeFromDequeRight();
		myStation.removeFromStation();
		myStation.printAll();
	}
	myStation.printAll();
}