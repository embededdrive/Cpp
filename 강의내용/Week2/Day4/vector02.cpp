#include <iostream>
#include <vector>

using namespace std;

// vector<자료형> 변수이름
vector<int> v;

int main()
{
	// capacity : 물리적 메모리 할당 (할당 방법은 컴파일러마다 다름)
	// 디버그 모드 조사식에서 확인가능

	v.push_back(1);	// 맨 뒤에 원소를 하나 추가
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(0);
	v.pop_back();	// 맨 뒤에 원소를 하나 지움


	return 0;
}