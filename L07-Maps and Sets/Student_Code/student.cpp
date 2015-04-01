#include "student.h"
#include <sstream>
#include <iostream>
#include <iomanip>
unsigned long long int Student::getID()
{
	return ID;
}

string Student::getName()
{
	return name;
}

void Student::addClass(string newClass)
{
	classes.push_back(newClass);
	return;
}

void Student::setAddress(string inaddress)
{
	address=inaddress;
	return;
}

void Student::setPhone(string inPhone)
{
	phone=inPhone;
	return;
}
void Student::setID(int id)
{
	ID=id;
	return;
}

void Student::setName(string iname)
{
	name=iname;
	return;
}

string Student::getGPA()
{
	if(this->numClasses==0)
	{
		return "0.00";
	}
	double gpa=this->points/this->numClasses;
	if(gpa==0.0)
	{
		return "0.00";
	}
	ostringstream strs;
	strs<<fixed<<setprecision(2)<<gpa;
	string str=strs.str();
	return str;
}

void Student::addGPA(double classGrade)
{
	//std::cout<<"adding gpa"<<endl;
	this->points+=classGrade;
	this->numClasses++;
}

string Student::toString()
{
	stringstream str;
	str<<this->getID()<<endl;
	str<<this->name<<endl<<this->address<<endl<<this->phone<<endl;
	str<<this->getGPA();
	return str.str();

}