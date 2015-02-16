#include "Factory.h"
#include "ExpressionManager.cpp"
//You may add #include statments here
using namespace std;

/*
	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
*/
//=======================================================================================
/*
	createManager()

	Creates and returns an object whose class extends ExpressionManagerInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "ExpressionManager", you might say, "return new ExpressionManager();".
*/
int main()
{
	ExpressionManager exman;
	cout<<"3 + 4 * 5"<<endl;
	cout<<exman.infixToPostfix("3 + 4 * 5")<<endl;
	cout<<exman.infixToPostfix("( 3 + 10 ) * ( 7 + 4 ) / 5")<<endl;
}
ExpressionManagerInterface* Factory::createManager()
{
	return NULL;//Modify this line
}
//=======================================================================================