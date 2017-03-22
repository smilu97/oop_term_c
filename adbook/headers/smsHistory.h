#pragma once
#include <list>
#include <string>
#include <map>
using namespace std;

class sHistory {
private :
	int id;
	string from;
	string content;
public :
	sHistory(int _id, string _from, string _content):
		id(_id), from(_from), content(_content) {}
	int    getId();
	string getFrom();
	string getContent();
	void   setFrom(string _from);
	void   setContent(string _content);
	void   setId(int _id);
};

typedef multimap<string, sHistory*> sHistoryIndex_from;
typedef multimap<int, sHistory*>    sHistoryIndex_id;

class smsHistory {
private :
	int maxId;
	sHistoryIndex_id   key_id;
	sHistoryIndex_from key_from;
public :
	smsHistory();
	~smsHistory();
	void insert(string from, string content);
	void except(sHistory* h);
	void clear();
	int size();
	sHistoryIndex_id::iterator begin();
	sHistoryIndex_id::iterator end();
	sHistoryIndex_from::iterator begin_from();
	sHistoryIndex_from::iterator end_from();	
	string toString();
	void fromString(string data);
	void save(string path);
	void load(string path);
};
