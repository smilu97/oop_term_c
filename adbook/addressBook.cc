#include "headers/addressBook.h"

addressBook::addressBook(string _name) {
	this->maxId = 0;
	this->name = _name;
}
addressBook::~addressBook() {
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		delete (it->second);
	}
}
string addressBook::getName() { return this->name; }

void addressBook::insert(string name, string phoneNumber) {
	int id = maxId++;
	unit* u = new unit(id, name, phoneNumber);
	key_id[id] = u;
	key_name.insert(make_pair(name, u));
	key_numb.insert(make_pair(phoneNumber, u));
}
unit* addressBook::select(int id) {
	auto it = key_id.find(id);
	if (it == key_id.end()) return NULL;
	return it->second;
}
unit* addressBook::selectByName(string name) {
	auto it = key_name.find(name);
	if (it == key_name.end()) return NULL;
	return it->second;
}
unit* addressBook::selectByNumb(string numb) {
	auto it = key_numb.find(numb);
	if (it == key_numb.end()) return NULL;
	return it->second;
}
void addressBook::deleteById(int id) {
	unit* u = select(id);
	if (u == NULL) return;
	exceptUnit(u);
}
void addressBook::deleteByName(string name) {
	unit* u = selectByName(name);
	if (u == NULL) return;
	exceptUnit(u);
}
void addressBook::deleteByNumb(string phoneNumber) {
	unit* u = selectByNumb(phoneNumber);
	if (u == NULL) return;
	exceptUnit(u);
}
string addressBook::toString() {
	string res;
	for(auto it=key_id.begin(); it != key_id.end(); ++it) {
		res.append(it->second->toString());
	}
	return res;
}
void addressBook::fromString(string raw) {
	const char* cstr = raw.c_str();
	int cursor = 0;
	int cursor2 = 0;
	int length = raw.length();
	while (cursor < length) {
		string name, numb;
		for(cursor2=cursor; cursor2<length && 
			cstr[cursor2]!=','; ++cursor2) {
			name += cstr[cursor2];
		} cursor = cursor2+1;
		for(cursor2=cursor; cursor2<length &&
			cstr[cursor2]!='\n'; ++cursor2) {
			numb += cstr[cursor2];
		} cursor = cursor2+1;
		insert(name, numb);
	}
}

void addressBook::exceptUnit(unit* u) {
	int id = u->getId();
	string name = u->getName();
	string numb = u->getPhoneNumber();
	key_id.erase(key_id.find(id));
	for(auto it=key_name.find(name);
		it != key_name.end() && it->second->getName()==name;
		++it) {
		if(it->second->getId() == id) {
			key_name.erase(it);
			break;
		}
	}
	for(auto it=key_numb.find(numb);
		it != key_numb.end() && it->second->getPhoneNumber()==numb;
		++it) {
		if(it->second->getId() == id) {
			key_numb.erase(it);
			break;
		}
	}
	delete u;
}

void addressBook::save(string path) {
	string data = toString();
	FILE* fd = fopen(path.c_str(), "wb");
	fprintf(fd, "%s", data.c_str());
	fclose(fd);
}
void addressBook::load(string path) {
	string data;
	char buffer[1024];
	FILE* fd = fopen(path.c_str(), "rb");
	while(~fscanf(fd, "%1024s", buffer)) {
		data.append(buffer);
		data.append("\n");
	}
	fclose(fd);
	fromString(data);
}
void addressBook::save() {
	save(name+".dat");
}
void addressBook::load() {
	load(name+".dat");
}
unsigned int addressBook::size() {
	return key_id.size();
}
map<int, unit*>::iterator addressBook::begin() {
	return key_id.begin();
}
map<int, unit*>::iterator addressBook::end() {
	return key_id.end();
}
MSUS::iterator addressBook::begin_name() {
	return key_name.begin();
}
MSUS::iterator addressBook::end_name() {
	return key_name.end();
}
MSUS::iterator addressBook::begin_numb() {
	return key_numb.begin();
}
MSUS::iterator addressBook::end_numb() {
	return key_numb.end();
}

bool addressBook::compare(unit& a, unit& b) {
	return a.getName().compare(b.getName());
}
