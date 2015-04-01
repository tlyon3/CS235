#pragma once
#include "StudentInterface.h"
#include <list>
#include <map>
class Student:public StudentInterface
{
private:
	unsigned long long int ID;
	string name;
	string address;
	string phone;
	list<string> classes;
	double points;
	double numClasses;
public:
	Student(){}
	Student(unsigned long long int inid, string inName,
		string inAddress, string inPhone)
	{
		ID=inid;
		name=inName;
		address=inAddress;
		phone=inPhone;
		points=0;
		numClasses=0;
	}
	void addClass(string newClass);
	~Student(){}
	unsigned long long int getID();
	string getName();
	string getGPA();
	void setAddress(string address);
	void setPhone(string phonenumber);
	void setID(int id);
	void setName(string name);
	void addGPA(double classGrade);
	string toString();
};