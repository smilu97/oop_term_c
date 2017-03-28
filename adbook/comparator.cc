#include "headers/comparator.h"

bool stringComp::operator()(string const &a, string const &b) {
	const char* ac = a.c_str();
	const char* bc = b.c_str();
	int len = a.length() < b.length() ? a.length() : b.length();
	for(int i = 0; i < len; ++i) {
		int dd = ac[i] - bc[i];
		if(dd < 0) return true;
		else if(dd > 0) return false;
	}
	return a.length() < b.length();
}

bool unitCompName::operator()(unit *a, unit *b) {
	return a->getName().compare(b->getName());
}
