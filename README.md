# 객체지향 프로그래밍 Term Project 1

## How to build

```shell
./build.sh
```

build.sh 스크립트를 이용해 adbook폴더의 API와 test0폴더의 테스트 어플리케이션 모두 빌드할 수 있습니다.

## Project Structure

- [x] Phone
- [x] SMSHistory (sHistory)
- [x] CallHistory (cHistory)
- [x] AddressBook (unit)

### Phone

핸드폰을 대표하는 클래스입니다. AddressBook, CallHistory, SMSHistory 를 하나씩 가지면서 실제 이벤트에 대한 컨트롤러 역할을 하도록 만듭니다.

### SMSHistory

SMS 기록을 저장하는 컨테이너입니다. RDBMS의 테이블 하나와 비슷한 동작을 하도록 설계했습니다. Row Unit은 sHistory객체 입니다. 거의 모든 Column에 대한 인덱스 정보를 담고 있으며 UNIQ속성을 가지지 않는 것을 고려하여 std::multimap으로 인덱싱합니다. 거의 모든 Column이 Indexed 상태이므로 따로 정렬은 할 필요가 없습니다.

### CallHistory

Call 기록을 저장하는 컨테이너입니다. SMSHistory와 비슷한 구조를 가지고 있습니다.

### AddressBook

전화번호와 실제 인물 정보를 매칭시키기 위한 정보를 담고 있는 컨테이너입니다. 이 또한 SMSHistory와 비슷한 구조를 가지고 있습니다. 

## How to import

adbook/headers/adbook.h 헤더파일 하나로 모든 API를 임포트 할 수 있습니다.

빌드할 때, adbook/adbook.o 오브젝트 파일과 같이 링크합니다. (adbook.o이 보이지 않는다면 아직 빌드되지 않은 것입니다. adbook폴더에서 `make` 명령으로 빌드할 수 있습니다.) 

## Usage

```C
#include "adbook/headers/adbook.h"
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv)
{
  phone p("PhoneName", "01012345678");
  
  p.createAddress("John", "01013467984");
  p.createAddress("Amy",  "0194567845");
  
  p.smsReceiveCallback("01013467984", "Hello This is John!");
  p.smsReceiveCallback("01078945687", "You may not know who I am");
  
  p.callReceiveCallback("0194567845"); // Amy's call
  p.callReceiveCallback("01078945687"); 
  
  p.save("save_A00"); // save to file "./save_A00"
  p.clear(); // delete from memory
  p.load("save_A00"); // load from "./save_A00" to memory
  
  return 0;
}
```

## Reference

[Reference](REFERENCE.md)

## Author

* 김영진 ( E-mail: smilup2244@gmail.com )
* 이재경 ( E-mail: leeeeeandy@gmail.com)

