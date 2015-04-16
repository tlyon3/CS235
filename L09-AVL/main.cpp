#include "./Student_Code/avl.cpp"
#include "./Student_Code/node.cpp"

using namespace std;

int main()
{
	AVL myavl;
	myavl.add(0);
	myavl.add(1);
	Node* root=myavl.getRootNode();
	Node* temp1=myavl.findNode(myavl.getRootNode(),1);
	myavl.add(2);
	Node* temp2=myavl.findNode(myavl.getRootNode(),2);
	myavl.add(3);
	Node* temp3=myavl.findNode(myavl.getRootNode(),3);
	cout<<"ROOT: " <<root->nodeInfo()<<endl;
	cout<<temp1->nodeInfo()<<endl;
	cout<<temp2->nodeInfo()<<endl;
	cout<<temp3->nodeInfo()<<endl;
	myavl.add(6);
	myavl.add(7);
	myavl.add(5);
	Node* temp5=myavl.findNode(myavl.getRootNode(),5);
	Node* temp6=myavl.findNode(myavl.getRootNode(),6);
	Node* temp7=myavl.findNode(myavl.getRootNode(),7);
	cout<<temp6->nodeInfo()<<endl;
	cout<<temp7->nodeInfo()<<endl;
	cout<<temp5->nodeInfo()<<endl;



	
}