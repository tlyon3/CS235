#include "./Student_Code/student.cpp"
#include "./Student_Code/school.cpp"
#include "./Student_Code/Factory.cpp"

int main()
{
	School MountainView;
	MountainView.importStudents("./files/studentListMap_Small.txt",
								"./files/studentListSet_Small.txt");
	MountainView.importGrades("./files/classListMap_Small.txt");
	MountainView.importGrades("./files/classListSet_Small.txt");
	for(auto s:MountainView.getSet())
	{
		cout<<s->toString()<<endl;
		cout<<"-------------"<<endl;
	}
	for(auto s:MountainView.getMap())
	{
		cout<<s.second->toString()<<endl;
		cout<<"----------"<<endl;
	}

	cout<<MountainView.queryMap("./files/queryMap_Small.txt")<<endl;
	cout<<MountainView.querySet("./files/querySet_Small.txt")<<endl;
	MountainView.clear();
	cout<<"MountainView cleared"<<endl;
	for(auto s:MountainView.getSet())
	{
		cout<<s->toString()<<endl;
		cout<<"-------------"<<endl;
	}
	for(auto s:MountainView.getMap())
	{
		cout<<s.second->toString()<<endl;
		cout<<"----------"<<endl;
	}
	cout<<"done printing MountainView students"<<endl;

}