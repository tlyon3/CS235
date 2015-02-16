#include "ExpressionManager.h"
#include <sstream>
#include <vector>
#include <locale>
#include <cctype>

using namespace std;

//infix: 3 * 4 + 5
//postfix: 3 4 * 5 +
//http://en.wikipedia.org/wiki/Shunting_yard_algorithm
int priority(const string& c)
{
	if(c=="*"||"/")
	{
		return 2;
	}
	if(c=="+"||"-")
	{
		return 1;
	}
	else return 0;
}
bool tryParse(const string &symbol)
{
	bool isNumber=false;
	for(unsigned int i=0;i<symbol.size();i++)
	{
		if(!isdigit(symbol[i]))
		{
			return false;
		}
		else
			return true;
	}
}
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
	
	stringstream postfix;
	vector<string> tokens;
	istringstream iss(infixExpression);
	while(iss)
	{
		string temp;
		iss>>temp;
		tokens.push_back(temp);
	}
	stack<string> myStack;
	vector<string> output;
	for(int i=0;i<tokens.size();i++)
	{
		if(tryParse(tokens[i]))
		{
			output.push_back(tokens[i]);
		}
		if(tokens[i]=="(")
		{
			myStack.push(tokens[i]);
		}
		if(tokens[i]==")")
		{
			while(!myStack.empty() && myStack.top() != "(")
			{
				output.push_back(myStack.top());
				myStack.pop();
			}
			myStack.pop();
		}
		if(tokens[i]=="}")
		{
			while(!myStack.empty() && myStack.top() != "{")
			{
				output.push_back(myStack.top());
				myStack.pop();
			}
			myStack.pop();
		}
		if(tokens[i]=="]")
		{
			while(!myStack.empty() && myStack.top() != "[")
			{
				output.push_back(myStack.top());
				myStack.pop();
			}
			myStack.pop();
		}
		if(isOperator(tokens[i]))
		{
			while(!myStack.empty() && priority(myStack.top()) >= priority(tokens[i]))
			{
				output.push_back(myStack.top());
				myStack.pop();
			}
			myStack.push(tokens[i]);
		}

	}
	while(!myStack.empty())
	{
		output.push_back(myStack.top());
		myStack.pop();
	}
	cout<<"Contents of output vector: ";
	for(int i=0;i<output.size();i++)
	{
		postfix<<output[i];
		postfix<<" ";
	}
	string out=postfix.str();
	return out;
}


string ExpressionManager::postfixEvaluate(string postfixExpression)
{

}

bool ExpressionManager::isBracket(const string& expression)
{
	string brackets[]={"{","(","["};
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
	string operators[]={"+","-","*","/"};
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

