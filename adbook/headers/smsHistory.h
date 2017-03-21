#pragma once
#include <list>
#include <string>
#include <map>
using namespace std;

class history {
private :
	int id;
	string from;
	string content;
public :
	history(int _id, string _from, string _content):
		id(_id), from(_from), content(_content) {}
	int    getId();
	string getFrom();
	string getContent();
	void   setFrom(string _from);
	void   setContent(string _content);
	void   setId(int _id);
};

typedef multimap<string, history*> historyIndex_from;
typedef multimap<int, history*>    historyIndex_id;

class smsHistory {
private :
	int maxId;
	historyIndex_id   key_id;
	historyIndex_from key_from;
public :
	smsHistory();
	~smsHistory();
	void insert(string from, string content);
	void except(history* h);
	int size();
	historyIndex_id::iterator begin();
	historyIndex_id::iterator end();
	historyIndex_from::iterator begin_from();
	historyIndex_from::iterator end_from();	
};
