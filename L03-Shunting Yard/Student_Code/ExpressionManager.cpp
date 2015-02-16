#include "ExpressionManager.h"
#include <sstream>
#include <vector>
#include <locale>
#include <cctype>

using namespace std;

//infix: 3 * 4 + 5
//postfix: 3 4 * 5 +
//http://en.wikipedia.org/wiki/Shunting_yard_algorithm

bool ExpressionManager::isBalanced(string expression)
{
	stack<string> bracketStack;
	istringstream ss(expression);
	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	for(int i=0;i<tokens.size();i++)
	{
		if(tokens[i]=="("||"{"||"[")
		{
			bracketStack.push(tokens[i]);
		}
		else if(tokens[i]==")")
		{
			if(bracketStack.top()=="(")
			{
				bracketStack.pop();
			}
			else return false;
		}
		else if(tokens[i]=="}")
		{
			if(bracketStack.top()=="{")
			{
				bracketStack.pop();
			}
			else return false;
		}
		else if(tokens[i]=="]")
		{
			if(bracketStack.top()=="[")
			{
				bracketStack.pop();
			}
			else return false;
		}

	}
	if (bracketStack.empty())
	{
		return true;
	}
	else return false;

}

string ExpressionManager::postfixToInfix(string postfixExpression)
{

}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	//for numbers: push
	//for operator: pop 2, push operator
	stack<string> myStack;
	istringstream ss(infixExpression);
	stringstream postfix;
	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	for(int i=0;i<tokens.size();i++)
	{
		if(isBracket(tokens[i]))
		{
			myStack.push(tokens[i]);
		}
		else if(isOperator(tokens[i]))
		{
			myStack.pop();
			myStack.pop();
			if(myStack.top()=="-"||"+")
			{
				if(tokens[i]=="*"||"/")
				{
					myStack.pop();
					myStack.push(tokens[i]);
				}
			}
			else myStack.push(tokens[i]);
		}
		else myStack.push(tokens[i]);
	}
	while(!myStack.empty())
	{
		postfix<<myStack.top();
		myStack.pop();
	}
	return postfix;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{

}

bool ExpressionManager::isBracket(const string& expression)
{
	string brackets[]={"{","(","[","}",")","]"};
	for(int i=0; i<6;i++)
	{
		if(expression==brackets[i])
		{
			return true;
		}
	}
	return false;
}
bool ExpressionManager::isOperator(const string& expression)
{
	string operators[]={"-","+","*","/"};
	for(int i=0;i<4;i++)
	{
		if(expression==operators[i])
		{
			return true;
		}
	}
	return false;
}
// void ExpressionManager::performOperation(const string& input, stack<int>& intstack)
// {
// 	int lVal, rVal, result;
// 	rVal = intstack.top();
// 	intstack.pop();

// 	lVal=intstack.top();
// 	intstack.pop();
// 	if(input=="-")
// 	{
// 		result=lVal-rVal;
// 	}
// 	else if(input=="+")
// 	{
// 		result=lVal+rVal;
// 	}
// 	else if(input=="/")
// 	{
// 		result=lVal/rVal;
// 	}
// 	else if(input=="*")
// 	{
// 		result=lVal*rVal;
// 	}
// 	else
// 	{
// 		result=lVal%rVal;
// 	}
// 	myintStack.push(result);
// }

