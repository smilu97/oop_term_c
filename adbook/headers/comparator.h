#pragma once
#include <cstring>
#include <string>
#include "unit.h"
using namespace std;
class stringComp {
public :
	bool operator()(string const &a, string const &b);
};
class unitCompName {
public:
	bool operator()(unit *a, unit *b);
};