#include "qs.h"
#include <sstream>

void QS::sortAll()
{
	sortAtN(0,(size-1));
}

void QS::sortAtN(int left, int right)
{
	if(left<right)
	{
		int pivot=medianOfThree(left,right);
		pivot=partition(left,right,pivot);
		sortAtN(left,pivot-1);
		sortAtN(pivot+1,right);
	}
}

int QS::medianOfThree(int left, int right)
{
	if(size==0) return -1;
	if(left>=right || right>size-1 || left<0) return -1;
	int middleIndex = (left+right)/2;
	if(array[left]>array[middleIndex])
	{
		int temp=array[left];
		array[left]=array[middleIndex];
		array[middleIndex]=temp;
	}
	if(array[left]>array[right])
	{
		int temp=array[left];
		array[left]=array[right];
		array[right]=temp;
	}
	if(array[middleIndex]>array[right])
	{
		int temp=array[middleIndex];
		array[middleIndex]=array[right];
		array[right]=temp;
	}

	return middleIndex;
}
int QS::partition(int left, int right, int pivotIndex)
{
	
	if(array==NULL)
		return -1;
	if(pivotIndex>right||pivotIndex<left)
		return -1;
	if(left<0 || right>size-1 || left>right)
		return -1;
	pivotIndex=medianOfThree(left,right);
	//cout<<"PIVOT VALUE: "<<array[pivotIndex]<<endl;
	int small[size];
	int large[size];
	int equal[size];
	int largecount=0;
	int smallcount=0;
	int equalcount=0;
	for(int i=left;i<=right;i++)
	{
		if(array[i]<array[pivotIndex])
		{
			//cout<<array[i]<<"<"<<array[pivotIndex]<<endl;
			small[smallcount]=array[i];
			//cout<<"SMALL: "<<small[smallcount]<<endl;
			smallcount++;
		}
		else if(array[i]>array[pivotIndex])
		{
			//cout<<array[i]<<">"<<array[pivotIndex]<<endl;
			large[largecount]=array[i];
			//cout<<"LARGE: "<<large[largecount]<<endl;
			largecount++;
		}
		else if(array[i]==array[pivotIndex])
		{
			//cout<<array[i]<<"="<<array[pivotIndex]<<endl;
			equal[equalcount]=array[i];
			//cout<<"EQUAL: "<<equal[equalcount]<<endl;
			equalcount++;
		}
	}
	// cout<<"LARGE AT 0: "<<large[0]<<endl;
	// cout<<"SMALL AT 0: "<<small[0]<<endl;
	// cout<<"EQUAL AT 0: "<<equal[0]<<endl;
	// cout<<"Small: [";
	// for(int i=0;i<smallcount;i++)
	// {
	// 	cout<<small[i];
	// 	if(i<smallcount-1) cout<<", ";
	// }
	// cout<<"]"<<endl;
	// cout<<"Equal: [";
	// for(int i=0;i<equalcount;i++)
	// {
	// 	cout<<equal[i];
	// 	if(i<equalcount-1) cout<<", ";
	// }
	// cout<<"]"<<endl;
	// cout<<"Large: [";
	// for(int i=0;i<largecount;i++)
	// {
	// 	cout<<large[i];
	// 	if(i<largecount-1) cout<<", ";
	// }
	// cout<<"]"<<endl;
	
	for(int i=0;i<smallcount;i++)
	{
		array[left+i]=small[i];
	}
	for(int i=0;i<equalcount;i++)
	{
		array[left+smallcount+i]=equal[i];
	}
	for(int i=0;i<largecount;i++)
	{
		array[left+smallcount+equalcount+i]=large[i];
	}
	return left+smallcount;

}

string QS::getArray()
{
	if(size==0)
		return "";
	stringstream arraystream;
	//arraystream<<"{";
	for(int i=0;i<size;i++)
	{
		arraystream<<array[i];
		if(i!=size-1)
		{
			arraystream<<",";
		}
	}

	//arraystream<<"}"<<endl;
	return arraystream.str();
}

int QS::getSize()
{
	return size;
}

void QS::addToArray(int value)
{
	if(size<capacity)
	{
		array[size]=value;
		size++;
	}
}

bool QS::createArray(int newCapacity)
{
	if(!arrayAvailable)
	{
		array = new int[newCapacity];
		arrayAvailable=true;
		capacity=newCapacity;
		return true;
	}
	else
	{
		clear();
		createArray(newCapacity);
	}
	return false;
}

string QS::toString()
{
	stringstream str;
	str<<"[";
	for(int i=0;i<size;i++)
	{
		str<<array[i];
		if(i<size-1)
		{
			str<<", ";
		}
	}
	str<<"]";
	return str.str();
}
void QS::clear()
{
	int* temp=array;
	delete[] temp;
	array=NULL;
	capacity=0;
	arrayAvailable=false;
	size=0;
}