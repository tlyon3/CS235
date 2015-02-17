#include "ExpressionManager.cpp"

int main()
{
	ExpressionManager exman;
	cout<<"3 + 4 * 5"<<endl;
	cout<<exman.infixToPostfix("3 + 4 * 5")<<endl;
	cout<<exman.infixToPostfix("10 + 7 + 8")<<endl;
	cout<<exman.infixToPostfix("( 3 + 10 ) * 7 + 4 / 5")<<endl;
	cout<<exman.infixToPostfix("( 1 + 2 ) * ( 3 / 4 ) - ( 5 + 6 )");
}