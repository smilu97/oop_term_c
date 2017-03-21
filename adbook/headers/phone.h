#pragma once
#include "manager.h"

class phone {
protected :
	manager address;
public:
	phone(string name): address(name) {}
	void callReceiveCallback (string senderPhoneNum);
};