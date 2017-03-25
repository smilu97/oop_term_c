#include "headers/phone.h"

void phone::callReceiveCallback(string from) {
	call.insert(from);
}
void phone::smsReceiveCallback(string senderPhoneNum, string content) {
	sms.insert(senderPhoneNum, content);
	unit* person = address.selectByNumb(senderPhoneNum);
	if (person != NULL) {
		time_t time;
		address.updateLatestSms(person->getId(), time);
	}
	else {
		address.insert(senderPhoneNum, senderPhoneNum);
		unit* newPerson = address.selectByNumb(senderPhoneNum);
		time_t time;
		address.updateLatestSms(newPerson->getId(), time);
	}
}
void phone::createAddress(string name, string numb) {
	address.insert(name, numb);
}
void saveChunk(FILE* fd, string chunk) {
	fprintf(fd, "%d\n%s\n", (int)chunk.size(), chunk.c_str());
}
void phone::save(string path) {
	FILE* fd = fopen(path.c_str(), "w");
	fprintf(fd, "%s\n%s\n", myName.c_str(), myPhoneNumber.c_str());
	saveChunk(fd, address.toString());
	saveChunk(fd, sms.toString());
	saveChunk(fd, call.toString());
	fclose(fd);
}
string loadChunk(FILE* fd) {
	int size;
	fscanf(fd, "%d", &size);
	string res;
	char buffer[65535];
	int buffer_idx = 0;
	int res_len = 0;
	fgetc(fd);
	while(res_len+buffer_idx < size) {
		char c = fgetc(fd);
		buffer[buffer_idx++] = c;
		if(buffer_idx >= 65534) {
			buffer[65534] = '\0';
			res.append(buffer);
			buffer_idx = 0;
			res_len += 65534;
		}
	}
	fgetc(fd);
	if (buffer_idx) {
		buffer[buffer_idx++] = '\0';
		res.append(buffer);
	}
	return res;
}
void phone::load(string path) {
	FILE* fd = fopen(path.c_str(), "r");
	char buffer[65535];
	fscanf(fd, "%s", buffer);
	myName.assign(buffer, strlen(buffer));
	fscanf(fd, "%s", buffer);
	myPhoneNumber.assign(buffer, strlen(buffer));
	address.fromString(loadChunk(fd));
	sms.fromString(loadChunk(fd));
	call.fromString(loadChunk(fd));
	fclose(fd);
}
void phone::clear() {
	myName.clear();
	myPhoneNumber.clear();
	address.clear();
	sms.clear();
	call.clear();
}