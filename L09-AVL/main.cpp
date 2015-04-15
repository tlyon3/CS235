#include "./Student_Code/avl.cpp"
#include "./Student_Code/node.cpp"

using namespace std;

int main()
{
	AVL myavl;
	myavl.add(1);
	Node* root=myavl.getRootNode();
	cout<<"ROOT: " <<root->nodeInfo()<<endl;
	Node* temp0=myavl.findNode(myavl.getRootNode(),1);
	cout<<temp0->nodeInfo()<<endl;
	myavl.add(2);
	Node* temp1=myavl.findNode(myavl.getRootNode(),2);
	cout<<temp1->nodeInfo()<<endl;
	
}