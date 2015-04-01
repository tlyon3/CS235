#include "./Student_Code/student.cpp"
#include "./Student_Code/school.cpp"
#include "./Student_Code/Factory.cpp"

int main()
{
	School MountainView;
	MountainView.importStudents("./files/studentListMap_Large.txt",
								"./files/studentListSet_Large.txt");
	MountainView.importGrades("./files/classListSet_Small.txt");
	// for(auto s:MountainView.getSet())
	// {
	// 	cout<<s->toString()<<endl;
	// 	cout<<"-------------"<<endl;
	// }
	// for(auto s:MountainView.getMap())
	// {
	// 	cout<<s.second->toString()<<endl;
	// 	cout<<"----------"<<endl;
	// }

	cout<<MountainView.queryMap("./files/query_Total.txt")<<endl;
	cout<<"QUERY SET"<<endl;
	cout<<MountainView.querySet("./files/query_Total.txt")<<endl;



}