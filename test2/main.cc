#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../adbook/headers/adbook.h"

bool test() {
    addressBook m("man");
    char buf[65536];
    
    srand(time(0));
    for(int i=0;i<20;++i) {
        sprintf(buf, "PERSON%d", rand()%100);
        string name(buf);
        sprintf(buf, "0102066%d", rand()%100);
        string numb(buf);
        m.insert(name, numb);
    }
    if (m.size() != 20) return true;
    printf("Size: %d\n", m.size());
    int cnt = 0;
    for(auto it = m.begin_name(); it != m.end_name(); ++it, ++cnt) {
        it->second->print();
    }
    if (cnt != 20) return true;
    m.save();
    return false;
}

int main(void)
{
    if (test()) {
        printf("Fail\n");
    } else {
        printf("Success\n");
    }
    return 0;
}
