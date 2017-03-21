#include "headers/smsHistory.h"

int    history::getId() { return id; }
string history::getFrom() { return from; }
string history::getContent() { return content; }
void   history::setFrom(string _from) { from=_from; }
void   history::setContent(string _content) { content=_content; }
void   history::setId(int _id) { id = _id; }
smsHistory::smsHistory() {
	maxId = 0;
}
smsHistory::~smsHistory() {
	for(auto it = key_id.begin(); it != key_id.end(); ++it) {
		delete it->second;
	}
}
int smsHistory::size() { return key_id.size(); }

historyIndex_from::iterator smsHistory::begin_from() { return key_from.begin(); }
historyIndex_from::iterator smsHistory::end_from() { return key_from.end(); }

void smsHistory::insert(string from, string content) {
	int id = maxId++;
	history* h = new history(id, from, content);
	key_id.insert(make_pair(id, h));
	key_from.insert(make_pair(from, h));
}
void smsHistory::except(history *h) {
	key_id.erase(key_id.find(h->getId()));
	key_from.erase(key_from.find(h->getFrom()));
}