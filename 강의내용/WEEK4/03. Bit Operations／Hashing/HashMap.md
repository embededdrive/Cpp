# Hash Map

## Key와 Value를 저장하는 자료구조  

- C++ : map, unordered_map
- Java : HashMap
- C#, Python : Dictionary

DAT와 유사하지만 단점을 보완한 자료구조이다.  

DAT에서는 정수의 최대 크기만큼의 사이즈를 가진 배열을 만들어야 한다.  

## Hash Function

아무리 큰 값이어도 정해진 크기의 bucket 내부에 저장하도록 하는 함수  
특정 값들을 찾아갈 수 있는 "KEY"로 변환하는 함수  

- C : 직접 구현  
- C++ : unordered_map (FNV-1a 방식)  
- JAVA : Collection  
- 기타 언어 : Default로 들어있음  

1. 효율성
   - Hash의 시간복잡도가 결정된다
2. Hash Collision
   - 키가 중복될 수 있다
   - 해결방법
     1.  Chaining (연결)
     2.  Open Addressing

### Chaining (연결)

같은 키를 가진 값이 있으면 연결시켜 준다
- 시간복잡도  
- 일반적
  - O(1)
- 다른경우(재확인필요)
  - O(1) ~ log(N)
  - 보통 STL을 사용할 경우
- 최악
  - O(N)

### Open Addressing

Key 값의 자리가 비어있지 않은경우
다음 비어있는 자리에 저장

## C++에서 쓸 수 있는 map의 종류

1. Unordered Map
   - 정렬되지 않은 맵
   - 내부구조 : hash-table
   - 새로 만들고, 삭제, 탐색의 시간복잡도 대부분? O(1) ~ O(logN)
   - string의 데이터를 전부 변환시켜야 한다
2. Map
   - 정렬된 맵
   - 내부구조 : red-black tree
   - 새로 만들고, 삭제, 탐색의 시간복잡도 모두 O(logN) 보장
   - 비교적으로 양이 많은 경우 불리하다
   - string을 Key로 쓸 때 유리하다


## 구현

MAP은 고유의 키 값을 가진다  
이미 존재하는게 있다면 덮어씌워지는게 아니라 무시하게 된다  

`unordered_map<key type, value type>`
``` C++
#include <iostream>
#include <unordered_map>

using namespace std;

int main()W
{
	int arr[] = { 1, 200000000, 300000000, 4, 5 };

	unordered_map<int, int> um;

	for (int i = 0; i < 5; i++)
	{
		um.insert({ arr[i], 1 });
	}

	cout << um[200000000];

	return 0;
}
```

