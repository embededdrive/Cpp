#include <iostream>

using namespace std;

/*
* 1. 규칙찾기
* 2. 기저조건
* 3. 하고싶은 처리
*
* 순서대로 작성
*/

void func1(int a) {
	// 2. 기저조건
	if (a > 2) return;

	// 3. 하고싶은 처리
	cout << a;

	// 1. 재귀 기본 구조
	func1(a + 1);
	func1(a + 1);
}

int main()
{
	func1(0);

	return 0;
}