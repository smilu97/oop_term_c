#pragma once
#include "addressBook.h"

class phone {
protected :
	addressBook address;
public:
	phone(string name): address(name) {}
	void callReceiveCallback (string senderPhoneNum);
};