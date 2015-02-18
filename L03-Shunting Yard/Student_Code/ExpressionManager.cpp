#include "ExpressionManager.h"
#include <sstream>
#include <vector>
#include <stack>
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
const OpMap::value_type assocs[5]=
	{
		OpMap::value_type("+",make_pair<int,int>(0, 0)),
		OpMap::value_type("-",make_pair<int,int>(0,0)),
		OpMap::value_type("*",make_pair<int,int>(5,0)),
		OpMap::value_type("/",make_pair<int,int>(5,0)),
		OpMap::value_type("%",make_pair<int,int>(5,0))
	};

const OpMap opmap(assocs, assocs + sizeof(assocs) / sizeof(assocs[0]));

int priority(const string& token1, const string& token2)
{
	const pair<int,int> p1 =opmap.find(token1)->second;
	const pair<int,int> p2 = opmap.find(token2)->second;

	return p1.first - p2.first;
}

bool ExpressionManager::isBalanced(string expression)
{
	istringstream ss(expression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	for(int i=0;i<tokens.size();i++)
	{
		string token=tokens[i];
		if(isBracket(token))
		{
			if(myStack.empty())
			{
				myStack.push(token);
			}
			else if(token==")")
			{
				if(myStack.top()=="(")
				{
					myStack.pop();
				}
				else return false;
			}
			else if(token=="}")
			{
				if(myStack.top()=="{")
				{
					myStack.pop();
				}
				else return false;
			}
			else if(token=="]")
			{
				if(myStack.top()=="[")
				{
					myStack.pop();
				}
				else return false;
			}
			else myStack.push(token);
		}

	}
	if(myStack.empty())
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
	cout<<"size: "<<tokens.size()<<endl;
	for(int i=0;i<tokens.size();i++)
	{
		cout<<"-----i: "<<i<<endl;
		cout<<"Stack: ";
		for(stack<string> dump=myStack;!dump.empty();dump.pop())
		{
			cout<<dump.top()<<" ";
		}
		cout<<endl<<"Output Queue: ";
		for(int i=0;i<output.size();i++)
		{
			cout<<output[i]<< " ";
		}
		cout<<endl;
		cout<<"Token: "<<tokens[i]<<endl;
		string token=tokens[i];
		if(isOperator(token))			//if token is an operator
		{
			cout<<token<<" ";
			cout<<"operator"<<endl;
			const string o1=token;
			if(myStack.empty())
			{
				cout<<o1<<" ";
				cout<<"Push op"<<endl;
				myStack.push(o1);
			}
			else 
			{
				string o2=myStack.top();
				cout<<o2<<" ";
				cout<<"o2 string"<<endl;	
				while(isOperator(o2) && 		//while there is an operator at the top
					((isAssociative(o1,0) && priority(o1,o2)<=0)//left-associtive and prec of o1<=o2
					|| (isAssociative(o1,1) && priority(o1,o2)<0)))//right_associative and prec of o1<o2
				{
					cout<<"while operator"<<endl;
					output.push_back(myStack.top());	//output to queue
					myStack.pop();
					if(!myStack.empty())
					{
						o2=myStack.top();		//set to next token
					}
					else break;
				}
				cout<<o1<<" ";
				cout<<"Push op"<<endl;
				myStack.push(o1);			//push o1 on stack
			}
			
		}
		else if(token=="(")
		{
			cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token==")")
		{
			cout<< "right bracket"<<endl;
			while(myStack.top()!="(")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				cout<<"output: "<<myStack.top()<<endl;
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
		else if(token=="{")
		{
			cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token=="}")
		{
			cout<< "right bracket"<<endl;
			while(myStack.top()!="{")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				cout<<"output: "<<myStack.top()<<endl;
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
		else if(token=="[")
		{
			cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token=="]")
		{
			cout<< "right bracket"<<endl;
			while(myStack.top()!="[")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				cout<<"output: "<<myStack.top()<<endl;
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
		else
		{
			output.push_back(token);
			cout<<token<<" ";
			cout<<"push number"<<endl;		//token is a number
		}		
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

int stackSize(stack<string> a)
{
	int count = 0;
	for(stack<string> dump=a;!dump.empty();dump.pop())
	{
		count++;
	}
	return count;
}
string ExpressionManager::postfixToInfix(string postfixExpression)
{
	istringstream ss(postfixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	string result;
	for(int i=0;i<tokens.size();i++)//3 4 * 5 +
	{
		cout<<"Stack: ";
		for(stack<string> dump=myStack;!dump.empty();dump.pop())
		{
			cout<<dump.top();
			cout<<", ";
		}
		cout<<endl;
		if(isOperator(tokens[i]))
		{
			cout<<tokens[i]<<" operator"<<endl;
			if(stackSize(myStack)<2)
			{
				cout<<"error"<<endl;
				//throw too few arguments
			}
			else 
			{
				string arg1=myStack.top();
				myStack.pop();
				string arg2=myStack.top();
				myStack.pop();
				result="( ";
				result+=arg2;
				result+=" ";
				result+=tokens[i];
				result+=" ";
				result+=arg1;
				result+=" )";
				myStack.push(result);
			}
		}
		else myStack.push(tokens[i]);
	}
	return result;
	
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	int lArg;
	int rArg;
	int iresult;
	string result;
	istringstream ss(postfixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	for(int i=0;i<tokens.size();i++)
	{
		if(isOperator(tokens[i]))
		{
			rArg=stoi(myStack.top());
			myStack.pop();
			lArg=stoi(myStack.top());
			myStack.pop();
			if(tokens[i]=="+")
			{
				iresult = lArg+rArg;
			}
			else if(tokens[i]=="-")
			{
				iresult = lArg-rArg;
			}
			else if(tokens[i]=="*")
			{
				iresult = lArg*rArg;
			}
			else if(tokens[i]=="/")
			{
				iresult = lArg/rArg;
			}
			else if(tokens[i]=="%")
			{
				iresult = lArg%rArg;
			}
			result=to_string(iresult);
			myStack.push(result);
		}
		else myStack.push(tokens[i]);
	}
	return result;
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

