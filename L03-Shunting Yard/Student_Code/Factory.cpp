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


// int main()
// {
// 	ExpressionManager exman;
// 	string postfix=exman.infixToPostfix("( 3 + 10 ) / ( 2 + 3 ) * 4");
// 	cout<<postfix<<endl;
// 	string pfix=exman.infixToPostfix("( 3 + 10 ) / 0 + 5");
// 	cout<<exman.postfixToInfix(postfix)<<endl;
// 	cout<<exman.infixToPostfix("a b ! t")<<endl;
// 	cout<<exman.postfixEvaluate(postfix)<<endl;
// 	cout<<exman.postfixEvaluate("a b ! t")<<endl;

// }
ExpressionManagerInterface* Factory::createManager()
{
	return new ExpressionManager();//Modify this line
}
//=======================================================================================