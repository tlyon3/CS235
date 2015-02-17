#include "ExpressionManager.h"
#include <sstream>
#include <vector>
#include <locale>
#include <cctype>
#include <list>
typedef map<string,pair<int,int> > OpMap;
typedef vector<string>::const_iterator cv_iter;
typedef	string::iterator s_iter;
using namespace std;

//infix: 3 * 4 + 5
//postfix: 3 4 * 5 +
//http://en.wikipedia.org/wiki/Shunting_yard_algorithm
const OpMap::value_type assocs[4]=
	{
		OpMap::value_type("+",make_pair<int,int>(0, 0)),
		OpMap::value_type("-",make_pair<int,int>(0,0)),
		OpMap::value_type("*",make_pair<int,int>(5,0)),
		OpMap::value_type("/",make_pair<int,int>(5,0))
	};
const OpMap opmap(assocs, assocs + sizeof(assocs) / sizeof(assocs[0]));

int priority(const string& token1, const string& token2)
{
	const pair<int,int> p1 =opmap.find(token1)->second;
	const pair<int,int> p2 = opmap.find(token2)->second;

	return p1.first - p2.first;
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
bool isAssociative(const string& token, const int& type)
{
	const pair<int,int> p=opmap.find(token)->second;
	return p.second == type;
}
string ExpressionManager::infixToPostfix(string infixExpression)
{
 	istringstream ss(infixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	vector<string> output;
	for(int i=0;i<tokens.size();i++)
	{
		const string token=tokens[i];
		if(isOperator(token))			//if token is an operator
		{
			const string o1=token;
			string o2=myStack.top();	
			while(isOperator(o2) && 		//while there is an operator at the top
				((isAssociative(o1,0) && priority(o1,o2)<=0)//left-associtive and prec of o1<=o2
				|| (isAssociative(o1,1) && priority(o1,o2)<0)))//right_associative and prec of o1<o2
			{
				output.push_back(myStack.top());	//output to queue
				myStack.pop();
				o2=myStack.top();		//set to next token
			}
			myStack.push(o1);			//push o1 on stack
		}
		if(token=="(")
		{
			myStack.push(token);
		}
		else if(token==")")
		{
			while(token!="(")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				myStack.pop();
			}
			if(!myStack.empty())
			{
				myStack.pop();				//pop left bracket, don't output
			}
			else if(myStack.empty())
			{
				cout<<"mismatched brackets"<<endl;
				//throw execption "mismatched brackets"
			}

		}
		else output.push_back(token);		//token is a number
	}

	while(!myStack.empty())					//pop and output rest of tokens
	{
		if(isBracket(myStack.top()))		//there shouldn't be any brackets left
		{
			cout<<"mismatched brackets"<<endl;
			//throw exception "mismatched brackets"
		}
		else
		{
			output.push_back(myStack.top());
			myStack.pop();
		} 
	}

	string postfix;
	for(int i=0;i<output.size();i++)//convert to string
	{
		postfix+=output[i];
		postfix+=" ";
	}
	return postfix;
}


string ExpressionManager::postfixToInfix(string postfixExpression)
{

}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{

}

bool ExpressionManager::isBracket(const string& token)
{
	return token=="("||token=="{"||token=="["||
		token==")"||token=="}"||token=="]";
}
bool ExpressionManager::isOperator(const string& token)
{
	return token=="+"||token=="-"||token=="*"||token=="/";
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

