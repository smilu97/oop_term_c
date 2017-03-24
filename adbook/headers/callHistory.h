#pragma once
#include <list>
#include <string>
#include <map>
#include <cstring>
using namespace std;

class cHistory {
private :
	int id;
	string from;
public :
	cHistory(int _id, string _from):
		id(_id), from(_from) {}
	int    getId();
	string getFrom();
	void   setFrom(string _from);
	void   setId(int _id);
	void   print();
};

typedef multimap<string, cHistory*> cHistoryIndex_from;
typedef multimap<int, cHistory*>    cHistoryIndex_id;

class callHistory {
private :
	int maxId;
	cHistoryIndex_id   key_id;
	cHistoryIndex_from key_from;
public :
	callHistory();
	~callHistory();
	void insert(string from);
	void except(cHistory* h);
	int size();
	void clear();
	cHistoryIndex_id::iterator begin();
	cHistoryIndex_id::iterator end();
	cHistoryIndex_from::iterator begin_from();
	cHistoryIndex_from::iterator end_from();
	string toString();
	void fromString(string data);
	void save(string path);
	void load(string path);
};
