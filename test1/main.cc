#include <cstdio>
#include "../adbook/headers/adbook.h"

bool test1() {
	addressBook m("man");
	char buf[100];
	string name, numb;
	for(int i=0;i<20;++i) {
		sprintf(buf, "PERSON%d", i);
		string name(buf);
		sprintf(buf, "0102066%d", i);
		string numb(buf);
		m.insert(name, numb);
	}
	m.save();
	return false;
}
bool test2() {
	addressBook m("man");
	m.load();
	int cnt = 0;
	for(auto it = m.begin(); it != m.end(); ++it) {
		it->second->print();
		++cnt;
	}
	if (cnt != 20) return true;
	return false;
}

int main(void)
{
	if(test1() || test2()) {
		printf("Fail\n");
	}
	else {
		printf("Success\n");
	}
	return 0;
}