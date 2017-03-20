#pragma once
#include <string>
using namespace std;

class unit {
protected :
	int id; // PK
	string name;
	string phoneNumber;
public :
	unit(int _id, string _name, string _phoneNumber):id(_id), name(_name), phoneNumber(_phoneNumber) {}
	int getId();
	void setId(int _id);
	string getName();
	void setName(string _name);
	string getPhoneNumber();
	void setPhoneNumber(string _phoneNumber);
	string toString();
	void print();
};