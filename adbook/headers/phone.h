#pragma once
#include "addressBook.h"
#include "smsHistory.h"
#include "callHistory.h"

class phone {
public:
	string myName;
	string myPhoneNumber;
	addressBook address; // address container
	smsHistory sms; // sms history container
	callHistory call; // calling history container
public:
	phone(string name, string phoneNumber): address(name), myPhoneNumber(phoneNumber),
		myName(name) {}
	string findNameByFrom(string from);
	void callReceiveCallback(string from);
	void smsReceiveCallback (string senderPhoneNum, string content);
	void createAddress(string name, string numb);
};