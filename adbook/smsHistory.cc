#include "headers/smsHistory.h"
#define BUFFER_SIZE 65535

int    sHistory::getId() { return id; }

string sHistory::getFrom() { return from; }

string sHistory::getContent() { return content; }

void   sHistory::setFrom(string _from) { from=_from; }

void   sHistory::setContent(string _content) { content=_content; }

void   sHistory::setId(int _id) { id = _id; }

void sHistory::print()
{
	printf("-----------------------\nfrom:%s\ncontent:%s\n",from.c_str(), content.c_str());
}

smsHistory::smsHistory() {
	maxId = 0;
}

smsHistory::~smsHistory() {
	clear();
}

void smsHistory::clear() {
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		delete it->second;
	}
	key_id.clear();
	key_from.clear();
}

int smsHistory::size() { return key_id.size(); }

sHistoryIndex_id::iterator smsHistory::begin() { return key_id.begin(); }

sHistoryIndex_id::iterator smsHistory::end() { return key_id.end(); }

sHistoryIndex_from::iterator smsHistory::begin_from() { return key_from.begin(); }

sHistoryIndex_from::iterator smsHistory::end_from() { return key_from.end(); }

sHistoryIndex_from::iterator smsHistory::find_from(string from) {
	return key_from.find(from);
}

void smsHistory::insert(string from, string content) {
	int id = maxId++;
	sHistory* h = new sHistory(id, from, content);
	key_id.insert(make_pair(id, h));
	key_from.insert(make_pair(from, h));
}

void smsHistory::except(sHistory *h) {
	key_id.erase(key_id.find(h->getId()));
	key_from.erase(key_from.find(h->getFrom()));
}

string smsHistory::toString() {
	string res;
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		res.append(it->second->getFrom() + ',' + it->second->getContent() + '\n');
	}
	return res;
}

void smsHistory::fromString(string data) {
	const char* cstr = data.c_str();
	int length = data.length();
	int cursor2;
	for(int cursor=0; cursor < length;) {
		string from, content;
		for(cursor2 = cursor; cursor2 < length && cstr[cursor2] != ','; ++cursor2) {
			from += cstr[cursor2];
		}
        cursor = cursor2 + 1;
		for(cursor2 = cursor; cursor2 < length && cstr[cursor2] != '\n'; ++cursor2) {
			content += cstr[cursor2];
		}
        cursor = cursor2 + 1;
		insert(from, content);
	}
}

void smsHistory::save(string path)
{
	FILE* fd = fopen(path.c_str(), "w");
	fprintf(fd, "%s", toString().c_str());
	fclose(fd);
}

void smsHistory::load(string path)
{
	FILE* fd = fopen(path.c_str(), "r");
	string data;
    char buffer[BUFFER_SIZE];
	while(~fscanf(fd, "%65535s", buffer)) {
		data.append(buffer);
	}
	fromString(data);
	fclose(fd);
}
