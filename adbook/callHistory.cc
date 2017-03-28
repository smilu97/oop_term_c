#include "headers/callHistory.h"
#define BUFFER_SIZE 65535

int    cHistory::getId() { return id; }

string cHistory::getFrom() { return from; }

void   cHistory::setFrom(string _from) { from = _from; }

void   cHistory::setId(int _id) { id = _id; }

void cHistory::print()
{
	printf("-----------------------\nfrom:%s\n", from.c_str());
}

callHistory::callHistory() {
	maxId = 0;
}

callHistory::~callHistory() {
	clear();
}

void callHistory::clear() {
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		delete it->second;
	}
	key_from.clear();
	key_id.clear();
}

int callHistory::size() { return key_id.size(); }

cHistoryIndex_id::iterator callHistory::begin() { return key_id.begin(); }

cHistoryIndex_id::iterator callHistory::end() { return key_id.end(); }

cHistoryIndex_from::iterator callHistory::begin_from() { return key_from.begin(); }

cHistoryIndex_from::iterator callHistory::end_from() { return key_from.end(); }

void callHistory::insert(string from) {
	int id = maxId++;
	cHistory* h = new cHistory(id, from);
	key_id.insert(make_pair(id, h));
	key_from.insert(make_pair(from, h));
}

void callHistory::except(cHistory *h) {
	key_id.erase(key_id.find(h->getId()));
	key_from.erase(key_from.find(h->getFrom()));
}

string callHistory::toString() {
	string res;
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		res.append(it->second->getFrom());
		res.append("\n");
	}
	return res;
}

void callHistory::fromString(string data) {
	const char* cstr = data.c_str();
	int cursor = 0;
	int cursor2 = 0;
	int length = data.length();
	while(cursor < length) {
		string from;
		for(cursor2 = cursor; cursor < length && cstr[cursor] != '\n'; ++cursor2) {
			from += cstr[cursor2];
		}
        cursor = cursor2 + 1;
		insert(from);
	}
}

void callHistory::save(string path) {
	FILE *fd = fopen(path.c_str(), "w");
	fprintf(fd, "%s", toString().c_str());
	fclose(fd);
}

void callHistory::load(string path) {
	FILE* fd = fopen(path.c_str(), "r");
	string data;
	char buffer[BUFFER_SIZE];
	while(~fscanf(fd, "%65535s", buffer)) {
		data.append(buffer);
	}
	fromString(data);
	fclose(fd);
}
