#include "QSInterface.h"

class QS: public QSInterface
{
private:
	int* array=NULL;
	bool arrayAvailable=false;
	int size=0;
	int capacity=0;
public:
	QS()
	{
		arrayAvailable=false;
		size=0;
		capacity=0;
		array=NULL;
	}
	~QS(){clear();}
	void sortAll();
	void sortAtN(int left,int right);
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
	int getCapacity();
	void addToArray(int value);
	bool createArray(int capacity);
	void clear();
	string toString();


};