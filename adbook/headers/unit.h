#pragma once
#include <string>
#include <ctime>
using namespace std;

class unit {
protected :
	int id; // PK
	string name;
	string phoneNumber;
	time_t latestSms;
public :
	unit(int _id, string _name, string _phoneNumber):id(_id), name(_name), phoneNumber(_phoneNumber), latestSms() {}
	int getId();
	void setId(int _id);
	string getName();
	void setName(string _name);
	string getPhoneNumber();
	void setPhoneNumber(string _phoneNumber);
	time_t getLatestSms();
	void setLatestSms(time_t _latestSms);
	string toString();
	void print();
};