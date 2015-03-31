#include "student.h"
#include <sstream>
#include <iostream>
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
	double gpa=this->points/this->numClasses;
	ostringstream strs;
	strs<<gpa;
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
	string str;
	str+=to_string(this->ID);
	str+="\n";
	str+=this->name;
	str+="\n";
	str+=this->address;
	str+="\n";
	str+=this->phone;
	str+="\n";
	str+=this->getGPA();
	return str;

}
