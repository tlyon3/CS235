#include "./Student_Code/qs.cpp"
#include <cstdlib>
using namespace std;
int main()
{
	srand(time(NULL));

	QS quickSort;
	quickSort.createArray(30);
	cout<<"Array: ";
	for(int i=0;i<30;i++)
	{
		int num=rand()%30+1;
		quickSort.addToArray(num);
	}
	cout<<quickSort.toString()<<endl;
	quickSort.sortAll();
	cout<<"Sorted array: "<<quickSort.toString()<<endl;
}
