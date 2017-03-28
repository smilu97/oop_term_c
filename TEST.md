# Test Application

## test1 

- p.createAddress Method를 통해 phone 객체에 주소록 20개 생성하였습니다. save 파일에 저장 후 phone 객체를 clear하고 reload하는 것도 문제없이 수행되는 것을 확인하였습니다.

## test2

- Red-Black tree로 구현된 multimap을 이용한 Indexing으로 Sorting 관련 문제를 수행하였습니다.

## test3 

- 10개 추가 생성하였으며, save 파일에 저장 후 phone 객체를 clear하고 reload하는 것도 문제없이 수행되는 것을 확인하였습니다.

## test4 

- save 파일 내에서 3개의 Entries 추가 후 2개 Entries 수정 / 1개 Entry 삭제 후 실행 결과 Sorting되는 것을 확인하였습니다.
- 프로그램이 멈춰 있는 동안 세이브 파일을 적당히 변경하고 진행하면 됩니다.

## test5 

- p.address.selectByName Method를 통해 phone의 address 객체에 접근하여 name으로 searching하는 것을 구현하였습니다.

## test6 

- multimap의 구조가 RB tree라는 것은 searching을 진행하는 데 time complexity가 O(logN)으로 가능하다는 것을 의미합니다. 이 Algorithm대로 browsing을 진행한다면 O(N)의 time complexity를 갖는 보통 우리가 생각하기 쉬운 browsing 방식인 순서대로 browsing하는 방식보다 더 효율적으로 browsing이 가능하다고 생각합니다.

## test7 

- 20개의 sms history를 smsReceiveCallback Method를 통해 생성하였고, 보여질 sms의 갯수 n을 입력받아 n개의 sms history를 save 파일에 저장하였습니다.
- 그리고 20개의 sms히스토리를 보여주며, addressBook에 저장된 번호일 경우 그 이름을 같이 출력했습니다.

## test8

- 20개의 call history를 callReceiveCallback Method를 통해 생성하였고, 이를 save 파일에 저장하였습니다.
- 여기서도 마찬가지로 20개의 call히스토리를 보여주며, addressBook에 저장된 번호일 경우 그 이름을 같이 출력했습니다.