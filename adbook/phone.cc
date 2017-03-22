#include "headers/phone.h"

void phone::callReceiveCallback(string from) {
	call.insert(from);
}
void phone::smsReceiveCallback(string senderPhoneNum, string content) {
	sms.insert(senderPhoneNum, content);	
}
void phone::createAddress(string name, string numb) {
	address.insert(name, numb);
}