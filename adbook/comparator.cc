#include "headers/comparator.h"

bool stringComp::operator()(string a, string b) {
	return a.compare(b);
}