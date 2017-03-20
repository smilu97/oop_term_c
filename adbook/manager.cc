#include "headers/manager.h"

manager::manager() {
	this->maxId = 0;
}

void manager::insert(string name, string phoneNumber) {
	int id = maxId++;
	unit* u = new unit(id, name, phoneNumber);
	key_id[id] = u;
	key_name[name] = u;
	key_numb[phoneNumber] = u;
}
unit* manager::select(int id) {
	auto it = key_id.find(id);
	if (it == key_id.end()) return NULL;
	return it->second;
}
unit* manager::selectByName(string name) {
	auto it = key_name.find(name);
	if (it == key_name.end()) return NULL;
	return it->second;
}
unit* manager::selectByNumb(string numb) {
	auto it = key_numb.find(numb);
	if (it == key_numb.end()) return NULL;
	return it->second;
}
void manager::deleteById(int id) {
	unit* u = select(id);
	if (u == NULL) return;
	exceptUnit(u);
}
void manager::deleteByName(string name) {
	unit* u = selectByName(name);
	if (u == NULL) return;
	exceptUnit(u);
}
void manager::deleteByNumb(string phoneNumber) {
	unit* u = selectByNumb(phoneNumber);
	if (u == NULL) return;
	exceptUnit(u);
}
string manager::toString() {
	string res;
	for(auto it=key_id.begin(); it != key_id.end(); ++it) {
		res.append(it->second.toString());
	}
	return res;
}
void manager::fromString(string raw) {
	char* cstr = raw.c_str();
	int cursor = 0;
	int length = raw.length();
	while (cursor < length) {
		string name(cstr+cursor);
		cursor += name.length() + 1;
		string numb(cstr+cursor);
		cursor += numb.length() + 1;
		insert(name, numb);
	}
}

void manager::exceptUnit(unit* u) {
	int id = u->getId();
	string name = u->getName();
	string numb = u->getPhoneNumber();
	key_id.erase(key_id.find(id));
	key_name.erase(key_name.find(name));
	key_numb.erase(key_numb.find(numb));
	delete u;
}

void manager::save(string path) {
	string data = toString();
	fd = fopen(path.c_str(), 'wb')
	fprintf(fd, "%s", data.c_str());
	fclose(fd);
}
void manager::load(string path) {
	string data;
	char buffer[1024];
	fd = fopen(path.c_str(), 'rb')
	while(~fscanf(fd, "%1024s", buffer)) {
		data.concat(buffer);
	}
	fclose(fd);
	fromString(data);
}