#include "ExpressionManagerInterface.h"

class ExpressionManager: public ExpressionManagerInterface
{
	ExpressionManager():ExpressionManagerInterface(){}
	~ExpressionManager(){}
	string postfixExpression;
	string infixExpression;
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);	
};