#include "ExpressionManagerInterface.h"

class ExpressionManager: public ExpressionManagerInterface
{
private:
	string postfixExpression;
	string infixExpression;
public:
	ExpressionManager():ExpressionManagerInterface(){}
	~ExpressionManager(){}
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);
	bool isBracket(const string& expression);
	bool isOperator(const string& expression);	
	// void performOperation(const string& input, stack<int>& intstack);
};