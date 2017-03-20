#include <vector>
#include <priority_queue>
#include "unit.h"
#include "comparator.h"
typedef priority_queue PQ;
using namespace std;

class manager {
protected :
	vector<unit*> units;
	PQ<unit*, unitNameComp> key_name;
	PQ<unit*, unitNumbComp> key_numb;
public :
	// CREATE
	void insert(string name, string phoneNumber);
	// READ
	unit* at(int idx);
	unit* select(int idx);
	unit* selectByName(string name);
	unit* selectByNumb(string numb);
	// UPDATE
	// DELETE
	void delete(int id);
	void deleteByName(string name);
	void deleteByNumb(string phoneNumber);
	// FILE
	string toString();
	void fromString(string raw);
}