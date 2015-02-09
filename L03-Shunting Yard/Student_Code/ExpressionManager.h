#include "ExpressionManagerInterface.h"

class ExpressionManager: public ExpressionManagerInterface
{
	ExpressionManager():ExpressionManagerInterface(){}
	~ExpressionManager(){}

	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);	
};