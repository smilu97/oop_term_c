#pragma once
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "unit.h"
#include "comparator.h"
using namespace std;

class manager {
protected :
	string name;
	unsigned long long maxId;
	map<int, unit*>   key_id;
	map<string, unit*, stringComp> key_name;
	map<string, unit*, stringComp> key_numb;
public :
	manager(string _name);
	~manager();
	string getName();
	// CREATE
	void insert(string name, string phoneNumber);
	// READ
	unit* select(int id);
	unit* selectByName(string name);
	unit* selectByNumb(string numb);
	// UPDATE
	// DELETE
	void deleteById(int id);
	void deleteByName(string name);
	void deleteByNumb(string phoneNumber);
	// FILE
	string toString();
	void fromString(string raw);
	// ETC
	void exceptUnit(unit* u);
	void save(string path);
	void load(string path);
	void save();
	void load();
	map<int, unit*>::iterator begin();
	map<int, unit*>::iterator end();
};