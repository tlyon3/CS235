#include "school.h"
#include "student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
map<unsigned long long int,StudentInterface*> School::getMap()
{
	return studentMap;
}

set<StudentInterface*,Comparator> School::getSet()
{
	return studentSet;
}

bool School::importStudents(string mapFileName,string setFileName)
{
/*
	getline(in,name);
	s=new Student(...);
	set.insert(s);
	map[ID]=s;
*/
	bool valid=true;
	vector<Student*> newSetStudents;
	vector<Student*> newMapStudents;
	map<unsigned long long int,StudentInterface*> sMap=studentMap;
	set<StudentInterface*,Comparator> sSet=studentSet;
	ifstream setFile(setFileName);
	ifstream mapFile(mapFileName);
	if(!setFile.is_open()||!mapFile.is_open())
	{
		//cout<<"INVALID FILE NAME"<<endl;
		return false;
	}
	while(!setFile.eof())
	{
		if(!valid)
			break;
		//stringstream sid;
		string name;
		string phone;
		string address;
		//cout<<"IMPORTING SET: ";
		try
		{
			// getline(setFile,sid);
			// if(sid.empty())
			// {
			// 	break;
			// }
			//cout<<endl;
			//cout<<sid<<endl;
			//unsigned long long int id=stoi(sid);
			unsigned long long int id;
			setFile>>id;
			setFile.ignore();
			if(setFile.fail())
			{
				valid=false;
				break;
			}
			getline(setFile,name);
			//cout<<name<<endl;
			getline(setFile,address);
			//cout<<address<<endl;
			getline(setFile,phone);
			//cout<<phone<<endl;
			//cout<<"---------------"<<endl;
			Student* s=new Student(id,name,address,phone);
			newSetStudents.push_back(s);
		}
		catch(...)
		{
			//cout<<"FAILED!"<<endl;
			//cout<<"---------------"<<endl;
			valid=false;
			break;
		}
		setFile.peek();
	}
	//cout<<"DONE!"<<endl;
	while(!mapFile.eof())
	{
		if(!valid)
			break;
		string sid;
		string name;
		string phone;
		string address;
		//cout<<"IMPORTING MAP: ";
		try
		{
			// getline(mapFile,sid);
			// if(sid.empty())
			// {
			// 	break;
			// }
			unsigned long long int id;
			mapFile>>id;
			mapFile.ignore();
			if(mapFile.fail())
			{
				valid=false;
				break;
			}
			//cout<<endl;
			//cout<<sid<<endl;
			getline(mapFile,name);
			//cout<<name<<endl;
			getline(mapFile,address);
			//cout<<address<<endl;
			getline(mapFile,phone);
			//cout<<phone<<endl;
			//cout<<"-----------"<<endl;
			Student* s=new Student(id,name,address,phone);
			newMapStudents.push_back(s);
		}
		catch(...)
		{
			//cout<<"FAILED!"<<endl;
			//cout<<"------------"<<endl;
			valid=false;
			break;
		}
		mapFile.peek();
	}
	if(!valid)
	{
		int i=0;
		//cout<<"DELETING NEW MAP STUDENTS"<<endl;
		for(i=0;i<newMapStudents.size();i++)
		{
			delete newMapStudents[i];
		}
		//cout<<"DELETED "<<i<<" STUDENT OBJECTS"<<endl;
		//cout<<"DELETING NEW SET STUDENTS"<<endl;
		for (i = 0; i < newSetStudents.size(); ++i)
		{
			delete newSetStudents[i];
		}
		//cout<<"DELETED "<<i<<" STUDENT OBJECTS"<<endl;
		newMapStudents.clear();
		newSetStudents.clear();

		return false;
	}
	else
	{
		for(int i=0;i<newMapStudents.size();i++)
		{
			studentMap[newMapStudents[i]->getID()]=
				newMapStudents[i];
		}
		for(int i=0;i<newSetStudents.size();i++)
		{
			studentSet.insert(newSetStudents[i]);
		}
		return true;
	}

}

bool School::importGrades(string fileName)
{
/*
	map<ID,SI*>
	map[ID]->addGPA();
	--------------
	for(SI* s:set)	//for each student in set of students
	{
		
	}
*/
	ifstream file(fileName);
	if(!file.is_open())
	{
		return false;
	}
	//cout<<"IMPORTING GRADES: ";
	while(!file.eof())
	{
		string sid;
		string newClass;
		string grade;
		try
		{
			getline(file,sid);
			if(sid.empty())
			{
				break;
			}
			//cout<<endl;
			//cout<<"Student: "<<sid<<endl;
			getline(file,newClass);
			//cout<<"Class: "<<newClass<<endl;
			getline(file,grade);
			//cout<<"Grade: "<<grade<<endl;
			unsigned long long int id=stoi(sid);
			//cout<<"converted sid"<<endl;
			//studentMap[id]->addClass(newClass);
			if(studentMap.find(id)!=studentMap.end())
			{
				studentMap[id]->addGPA(gradeMap[grade]);
			}
			//cout<<"added gpa"<<endl;
			//cout<<"finding id"<<endl;
			for(StudentInterface* s:studentSet)
			{
				if (id==s->getID())
				{
					//cout<<"found id"<<id<<endl;
					//s->addClass(newClass);
					s->addGPA(gradeMap[grade]);
				}
			}
		}
		catch(...)
		{
			return false;
		}
	}
	return true;
}

string School::querySet(string fileName)
{
	ifstream file(fileName);
	stringstream str;
	if(file.is_open())
	{
		while(!file.eof())
		{
			string id;
			try
			{
				// getline(file,id);
				// if(id.empty())
				// {
				// 	break;
				// }
				unsigned long long int sID;
				file>>sID;
				file.ignore();
				if(file.fail())
				{
					break;
				}
				for(StudentInterface* s:studentSet)
				{
					if(sID==s->getID())
					{
					// {
					// 	str+=id;
					// 	str+=" ";
					// 	str+=s->getGPA();
					// 	str+=" ";
					// 	str+=s->getName();
					// 	str+="\n";
						str<<s->getID()<<" "<<s->getGPA()<<" "
						<<s->getName()<<endl;
						break;
					}
				}
			}
			catch(...)
			{
				return str.str();
			}
		}
	}
	return str.str();

}

string School::queryMap(string fileName)
{
	ifstream file(fileName);
	stringstream str;
	if(file.is_open())
	{
		while(!file.eof())
		{
			//cout<<"NEXT ITERATION"<<endl;
			string id;
			try
			{
				// getline(file,id);
				// if(id.empty())
				// {
				// 	break;
				// }
				unsigned long long int sID;
				file>>sID;
				//cout<<"ID: "<<sID<<endl;
				file.ignore();
				if(file.fail())
				{
					break;
				}
				if(studentMap.find(sID)!=studentMap.end())
				{
					//cout<<"ADDING: " <<sID<<endl;
					str<<sID<<" "<<studentMap[sID]->getGPA()<<" "
					<<studentMap[sID]->getName()<<endl;
				}
			}
			catch(...)
			{
				//cout<<"FAILED FULL INPUT"<<endl;
				return str.str();
			}
		}
	}
	return str.str();
}

void School::clear()
{
	for(auto& s:studentSet) delete s;
	studentSet.clear();
	for(auto& p:studentMap) delete p.second;
	studentMap.clear();
}