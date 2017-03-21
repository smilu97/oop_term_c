#include <cstdio>
#include <cstdlib>
#include "../adbook/headers/adbook.h"

bool test() {
    manager m("man");
    char buf[100];
    string name, numb;
    
    srand(100);
    for(int i=0;i<20;++i) {
        sprintf(buf, "PERSON%d", rand());
        string name(buf);
        sprintf(buf, "0102066%d", rand());
        string numb(buf);
        m.insert(name, numb);
    }
    sort(m.begin(), m.end(), m.compare());
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
