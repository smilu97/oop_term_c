#include "headers/unit.h"

int  unit::getId() { return this->id; }
void unit::setId(int _id) { this->id = _id; }
string unit::getName() { return this->name; }
void unit::setName(string _name) { this->name = _name; }
string unit::getPhoneNumber() { return this->phoneNumber; }
void unit::setPhoneNumber(string _phoneNumber) { this->phoneNumber = _phoneNumber; }
string unit::toString() {
	string res;
	res = name + "," + phoneNumber + "\n";
	return res;
}
void unit::print() {
	printf("-----------------------\nname:%s\nnumber:%s\n",
		name.c_str(), phoneNumber.c_str());
}