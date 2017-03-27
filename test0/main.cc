#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../adbook/headers/adbook.h"

int random(int from, int to)
{
	return rand()%(to-from+1)+from;
}

string createRandomString(int length, int from='a', int to='z')
{
	string res;
	for(int i=0;i<length;++i) {
		res.push_back(random(from,to));
	}
	return res;
}

bool test1(phone &p)
{
	printf("------------------TEST1 START------------------\n");
	for(int i=0;i<20;++i) {
		p.createAddress(createRandomString(random(20,30)), createRandomString(11,'0','9'));
	}
	printf("Created 20 units\n");
	p.save("save");
	printf("Saved instance\n");
	p.clear();
	printf("Cleared instance\n");
	p.load("save");
	printf("Reloaded instance\n");
	if (p.address.size() != 20) return false;
	for(auto it = p.address.begin(); it != p.address.end(); ++it) {
		it->second->print();
	}
	return true;
}
bool test2(phone &p)
{
	printf("------------------TEST2 START------------------\n");
	for(auto it = p.address.begin_name(); it != p.address.end_name(); ++it) {
		it->second->print();
	}	
	return true;
}
bool test3(phone &p)
{
	printf("------------------TEST3 START------------------\n");
	for(int i=0;i<10;++i) {
		p.createAddress(createRandomString(random(20,30)), createRandomString(11,'0','9'));
	}
	printf("Created 10 units\n");
	p.save("save");
	printf("Saved instance\n");
	p.clear();
	printf("Cleared instance\n");
	p.load("save");
	printf("Reloaded instance\n");
	if (p.address.size() != 30) return false;
	for(auto it = p.address.begin(); it != p.address.end(); ++it) {
		it->second->print();
	}
	return true;
}
bool test4(phone &p)
{
    printf("------------------TEST4 START------------------\n");
	p.save("save");
	printf("Modify \"save\" file in same folder and press any key to continue\n");
	getchar();
	p.clear();
	p.load("save");
	for(auto it = p.address.begin(); it != p.address.end(); ++it) {
		it->second->print();
	}
	return true;
}
bool test5(phone &p)
{
	char name[65536];
    printf("------------------TEST5 START------------------\n");
	printf("Input name: "); scanf("%s", name);
	string s_name(name);
	unit* found = p.address.selectByName(s_name);
	if (found == NULL) printf("Not found\n");
	else found->print();
	return true;
}
bool test6(phone &p)
{
	char phoneNumber[65535];
    printf("------------------TEST6 START------------------\n");
	printf("Input phone number: "); scanf("%s", phoneNumber);
	string s_phoneNumber(phoneNumber);
	unit* found = p.address.selectByNumb(s_phoneNumber);
	if (found == NULL) printf("Not found\n");
	else found->print();
	return true;
}
bool test7(phone &p)
{
	int i=0;
    printf("------------------TEST7 START------------------\n");
	for(auto it = p.address.begin(); it != p.address.end(); ++it,++i) {
		if (i>=15) break;
		p.smsReceiveCallback(it->second->getPhoneNumber(), createRandomString(100));
	}
	for(int i=0;i<5;++i) {
		p.smsReceiveCallback(createRandomString(11,'0','9'), createRandomString(100));
	}
	i=1;
	for(auto it = p.address.begin_smst(); it != p.address.end_smst(); ++it) {
		printf("%d. %s\n", i, it->second->getName().c_str());
		++i;
	}
	int idx;
	printf("the number of person to find sms history: "); scanf("%d", &idx);
	if (i-1 < idx) {
		printf("Too big index\n");
		return true;
	}
	auto u_it = p.address.begin_smst();
	for(int i=1;i<idx;++i) ++u_it;
	unit* u = u_it->second;
	string from = u->getPhoneNumber();

	printf("**************SMS HISTORY of %s*************************\n", u->getName().c_str());
	for(auto it = p.sms.find_from(from); it->second->getFrom()==from; ++it) {
		it->second->print();
	}
	return true;
}
bool test8(phone &p)
{
	int i=0;
    printf("------------------TEST8 START------------------\n");
	for(auto it = p.address.begin(); it != p.address.end(); ++it,++i) {
		if (i>=15) break;
		p.callReceiveCallback(it->second->getPhoneNumber());
	}
	for(int i=0;i<5;++i) {
		p.callReceiveCallback(createRandomString(11,'0','9'));
	}
	printf("**************CALL HISTORY*************************\n");
	for(auto it = p.call.begin(); it != p.call.end(); ++it) {
		it->second->print();
		unit* sender = p.address.selectByNumb(it->second->getFrom());
		if (sender != NULL) {
			printf("sender: %s\n", sender->getName().c_str());
		}
	}
	p.save("save");
	return true;
}
int main(void)
{
	srand(time(0));
	phone p("TESTER", "01012345678"); // create instance
	if(!test1(p) || !test2(p) || !test3(p) || !test4(p) || !test5(p) ||
		!test6(p) || !test7(p) || !test8(p)) {
		printf("Fail\n");
	}
	else {
		printf("Success\n");
	}
}
