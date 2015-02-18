#include "ExpressionManager.cpp"

int main()
{
	ExpressionManager exman;
	cout<<exman.postfixToInfix("3 4 * 5 +")<<endl;
	cout<<exman.postfixEvaluate("3 4 * 5 +")<<endl;
}