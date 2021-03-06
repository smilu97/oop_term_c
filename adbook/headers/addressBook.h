#pragma once
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "unit.h"
#include "comparator.h"
using namespace std;

typedef multimap<string, unit*, stringComp> MSUS;
typedef multimap<time_t, unit*> MTU;

class addressBook {
protected :
	string name;
	unsigned long long maxId;
	map<int, unit*>   key_id;
	MSUS key_name; // Index of name
	MSUS key_numb; // Index of phone number
	MTU key_smst; // Index of latest SMS Time
public :
	addressBook(string _name);
	~addressBook();
	string getName();
    
	// CRUD-CREATE
	void insert(string name, string phoneNumber);
    
	// CRUD-READ
	unit* select(int id);
	unit* selectByName(string name);
	unit* selectByNumb(string numb);
    
	// CRUD-UPDATE
	bool updateName(int id, string _name);
	bool updateNumb(int id, string _numb);
	bool updateLatestSms(int id, time_t _latestSms);
    
	// CRUD-DELETE
	bool deleteById(int id);
	bool deleteByName(string name);
	bool deleteByNumb(string phoneNumber);
    
	// FILE
	string toString();
	void fromString(string raw);
    
	// ETC
	void exceptUnit(unit* u);
	void save(string path);
	void load(string path);
	void clear();
	unsigned int size();
	map<int, unit*>::iterator begin();
	map<int, unit*>::iterator end();
	MSUS::iterator begin_name();
	MSUS::iterator end_name();
	MSUS::iterator begin_numb();
	MSUS::iterator end_numb();
	MTU::iterator  begin_smst();
	MTU::iterator  end_smst();
    bool compare(unit& a, unit& b);
};
