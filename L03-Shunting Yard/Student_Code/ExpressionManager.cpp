#include "ExpressionManager.h"
#include <sstream>
#include <vector>
#include <stack>
#include <locale>
#include <cctype>
#include <list>
#include <algorithm>
#include <iterator>
typedef map<string,pair<int,int> > OpMap;
typedef vector<string>::const_iterator cv_iter;
typedef	string::iterator s_iter;
using namespace std;
ExpressionManager::~ExpressionManager(){}
//infix: 3 * 4 + 5
//postfix: 3 4 * 5 +
//http://en.wikipedia.org/wiki/Shunting_yard_algorithm
static inline std::string &rtrim(std::string &s) 
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}
bool ExpressionManager::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
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
	if(validInfix(infixExpression)==false)
	{
		return "invalid";
		//throw exception
	}
	if(!validAmount(infixExpression))
	{
		return "invalid";
	}
 	istringstream ss(infixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	vector<string> output;
	//cout<<"size: "<<tokens.size()<<endl;
	for(int i=0;i<tokens.size();i++)
	{
		
		//cout<<"-----i: "<<i<<endl;
		//cout<<"Stack: ";
		// for(stack<string> dump=myStack;!dump.empty();dump.pop())
		// {
		// 	cout<<dump.top()<<" ";
		// }
		//cout<<endl<<"Output Queue: ";
		// for(int i=0;i<output.size();i++)
		// {
		// 	cout<<output[i]<< " ";
		// }
		// cout<<endl;
		// cout<<"Token: "<<tokens[i]<<endl;
		string token=tokens[i];
		if(isOperator(token))			//if token is an operator
		{
			// cout<<token<<" ";
			// cout<<"operator"<<endl;
			const string o1=token;
			if(myStack.empty())
			{
				// cout<<o1<<" ";
				// cout<<"Push op"<<endl;
				myStack.push(o1);
			}
			else 
			{
				string o2=myStack.top();
				// cout<<o2<<" ";
				// cout<<"o2 string"<<endl;	
				while(isOperator(o2) && 		//while there is an operator at the top
					((isAssociative(o1,0) && priority(o1,o2)<=0)//left-associtive and prec of o1<=o2
					|| (isAssociative(o1,1) && priority(o1,o2)<0)))//right_associative and prec of o1<o2
				{
					// cout<<"while operator"<<endl;
					output.push_back(myStack.top());	//output to queue
					myStack.pop();
					if(!myStack.empty())
					{
						o2=myStack.top();		//set to next token
					}
					else break;
				}
				// cout<<o1<<" ";
				// cout<<"Push op"<<endl;
				myStack.push(o1);			//push o1 on stack
			}
			
		}
		else if(token=="(")
		{
			// cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token==")")
		{
			// cout<< "right bracket"<<endl;
			while(myStack.top()!="(")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				// cout<<"output: "<<myStack.top()<<endl;
				myStack.pop();
			}
			if(!myStack.empty())
			{
				myStack.pop();				//pop left bracket, don't output
			}
			else if(myStack.empty())
			{
				//cout<<"mismatched brackets"<<endl;
				return "invalid";
				//throw execption "mismatched brackets"
			}

		}
		else if(token=="{")
		{
			// cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token=="}")
		{
			// cout<< "right bracket"<<endl;
			while(myStack.top()!="{")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				// cout<<"output: "<<myStack.top()<<endl;
				myStack.pop();
			}
			if(!myStack.empty())
			{
				myStack.pop();				//pop left bracket, don't output
			}
			else if(myStack.empty())
			{
				return "invalid";
				//throw execption "mismatched brackets"
			}

		}
		else if(token=="[")
		{
			// cout<<"bracket"<<endl;
			myStack.push(token);
		}
		else if(token=="]")
		{
			// cout<< "right bracket"<<endl;
			while(myStack.top()!="[")				//pop everything until left-bracket
			{
				output.push_back(myStack.top()); //output token to queue
				// cout<<"output: "<<myStack.top()<<endl;
				myStack.pop();
			}
			if(!myStack.empty())
			{
				myStack.pop();				//pop left bracket, don't output
			}
			else if(myStack.empty())
			{
				return "invalid";
				//throw execption "mismatched brackets"
			}

		}
		else
		{
			output.push_back(token);
			// cout<<token<<" ";
			// cout<<"push number"<<endl;		//token is a number
		}		
	}

	while(!myStack.empty())					//pop and output rest of tokens
	{
		if(isBracket(myStack.top()))		//there shouldn't be any brackets left
		{
			return "invalid";
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
	postfix=rtrim(postfix);
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
		// cout<<"Stack: ";
		// for(stack<string> dump=myStack;!dump.empty();dump.pop())
		// {
		// 	cout<<dump.top();
		// 	cout<<", ";
		// }
		// cout<<endl;
		if(!validAmount(postfixExpression))
		{
			return "invalid";
		}
		if(isOperator(tokens[i]))
		{
			// cout<<tokens[i]<<" operator"<<endl;
			if(stackSize(myStack)<2)
			{
				return "invalid";
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
	if(!validPostfix(postfixExpression))
	{
		return "invalid";
	}
	if(!validAmount(postfixExpression))
	{
		return "invalid";
	}
	int lArg;
	int rArg;
	int iresult;
	string result;
	istringstream ss(postfixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	stack<string> myStack;
	if(tokens.size()==1&&is_number(tokens[0]))
	{
		return tokens[0];
	}
	if(!is_number(tokens[0]))
	{
		return "invalid";
	}
	if(!is_number(tokens[1]))
	{
		return "invalid";
	}
	for(int i=0;i<tokens.size();i++)
	{
		if(isOperator(tokens[i]))
		{
			if(myStack.size()>=2)
			{
				rArg=stoi(myStack.top());
				myStack.pop();
				lArg=stoi(myStack.top());
				myStack.pop();
			}
			else return "invalid";
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
				if(rArg==0)
				{
					return "invalid";
					//throw exception
				}
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
	return token=="+"||token=="-"||token=="*"||token=="/"||token=="%";
}
bool ExpressionManager::validAmount(string expression)
{
	stringstream ss(expression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	int op=0;
	int num=0;
	for(int i=0;i<tokens.size();i++)
	{
		if(isOperator(tokens[i]))
		{
			op++;
		}
		else if(is_number(tokens[i]))
		{
			num++;
		}
	}
	// cout<<"Operators: "<<op<<endl;
	// cout<<"Numbers: "<<num<<endl;
	if(op==(num-1))
	{
		return true;
	}
	else return false;
}
bool ExpressionManager::validInfix(string infixexpression)
{
	if(isBalanced(infixexpression)==false)
	{
		return false;
	}
	//cout<<"check valid infix: "<<infixExpression<<endl;
	//string validEntries[]={"1","2","3","4","5","6","7","8","9","0"
							//"(",")","{","}","[","]","+","-","*","/","%"};
	bool found=false;
	stringstream ss(infixexpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	for(int i=0;i<tokens.size();i++)
	{
		if(isOperator(tokens[i])||is_number(tokens[i])||isBracket(tokens[i]))
		{
			found = true;
		}
		else return false;
	}
	//cout<<"valid"<<endl;
	return true;
}
bool ExpressionManager::validPostfix(string postfixExpression)
{
	bool found=false;
	stringstream ss(postfixExpression);
 	istream_iterator<string> begin(ss),end;
	vector<string> tokens(begin,end);
	
	for(int i=0;i<tokens.size();i++)
	{	
		if(isBracket(postfixExpression))
		{
			return false;
		}
		if(isOperator(tokens[i])||is_number(tokens[i]))
		{
			found = true;
		}
		else return false;

	}
	return found;
}