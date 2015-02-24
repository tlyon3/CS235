#pragma once
#include "StationInterface.h"
#include "stack.h"
#include "queue.h"
#include "deque.h"

class Station:public StationInterface
{
private:
	int currentCar;
	Stack<int> stationStack;
	Queue<int> stationQueue;
	Deque<int> stationDeque;
public:
	Station();
	~Station(){}

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();
	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();
	void printAll();
};