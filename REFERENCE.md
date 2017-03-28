# Phone

## Variables

`string myName`

핸드폰 소유주의 이름

`string myPhoneNumber`

핸드폰 고유 전화번호

`addressBook address`

주소 컨테이너

`smsHistory sms`

SMS 기록 컨테이너

`callHistory call`

전화 기록 컨테이너

## Member functions

`phone(string name, string phoneNumber)`

이름과 핸드폰의 번호를 받습니다.

`string findNameByFrom(string from)`

핸드폰 번호를 이용해서 이름을 찾습니다.

`void callReceiveCallback(string from)`

from의 핸드폰 번호로 부터 전화를 받았을 때 호출되어야 합니다.

`void smsReceiveCallback(string senderPhoneNum, string content)`

senderPhoneNum의 번호로 부터 문자를 받았을 때 호출되어야 합니다.

`void createAddress(string name, string numb)`

전화번호부에 유닛을 추가합니다

`void printAddress()`

전화번호부의 모든 유닛을 출력합니다.

`void save(string path)`

path에 현재 Phone이 가지고 있는 모든 정보를 저장합니다.

`void load(string path)`

path로 부터 정보를 불러들입니다. save(string)으로 저장한 파일이어야 합니다.

`void clear()`

모든 정보를 삭제합니다.

# addressBook

## Member functions

`void insert(string name, string phoneNumber)`

전화번호부에 기록을 추가합니다.

`unit* select...([int id, string name, string phoneNumber])`

주어진 인자를 가지고 unit 객체를 가리키는 포인터를 반환합니다.

인자에 따라 함수이름은 각각 (id, name, phoneNumber) => (select, selectByName, selectByNumb) 가 됩니다.

`bool update...(int id, [string name, string numb, time_t latestSms])`

특정 아이디를 가진 unit객체의 정보를 업데이트합니다.

updateName, updateNumb, updateLatestSms등이 있습니다.

`string toString()`

가지고 있는 모든 정보를 string객체에 담아 반환합니다.

`void fromString(string raw)`

string객체에 담겨있는 정보를 가지고 저장합니다. 저장형식은 toString()이 사용하는 것과 같아야 합니다.

`unsigned int size()`

저장하고 있는 unit객체의 개수를 반환합니다.

### Iterator Getters

```
map<int, unit*>::iterator begin();
map<int, unit*>::iterator end();
MSUS::iterator begin_name();
MSUS::iterator end_name();
MSUS::iterator begin_numb();
MSUS::iterator end_numb();
MTU::iterator  begin_smst();
MTU::iterator  end_smst();
```

각각 컬럼의 인덱스의 순환 반복자를 반환합니다. 반복자를 이용할 때는 _뒤의 이름의 컬럼을 기준으로 정렬됩니다.

# callHistory, smsHistory 

addressBook과 매우 유사한 구조를 가지고 있습니다. 자세한 사항은 소스코드를 직접 참조해주세요.

