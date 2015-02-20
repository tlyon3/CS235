#pragma once
#include "ExpressionManagerInterface.h"
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

class ExpressionManager: public ExpressionManagerInterface
{
private:
	string postfixExpression;
	string infixExpression;
public:
	ExpressionManager(){}
	~ExpressionManager();
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);
	bool isBracket(const string& expression);
	bool isOperator(const string& expression);	
	bool validInfix(string infixexpression);
	bool validPostfix(string postfixExpression);
	bool validAmount(string expression);
	bool is_number(const std::string& s);
};