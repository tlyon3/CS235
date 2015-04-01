#pragma once
#include "GPAInterface.h"
#include "student.h"

class School:public GPAInterface
{
private:
	map<unsigned long long int,StudentInterface*> studentMap;
	set<StudentInterface*,Comparator> studentSet;
public:
	map<string,double> gradeMap;
	School()
	{
		gradeMap["A"]=4.0;
		gradeMap["A-"]=3.7;
		gradeMap["B+"]=3.4;
		gradeMap["B"]=3.0;
		gradeMap["B-"]=2.7;
		gradeMap["C+"]=2.4;
		gradeMap["C"]=2.0;
		gradeMap["C-"]=1.7;
		gradeMap["D+"]=1.4;
		gradeMap["D"]=1.0;
		gradeMap["D-"]=0.7;
		gradeMap["E"]=0.0;
	}
	~School()
	{
		clear();
	}
	map<unsigned long long int,StudentInterface*> getMap();
	set<StudentInterface*,Comparator> getSet();
	bool importStudents(string mapFileName,string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();
};