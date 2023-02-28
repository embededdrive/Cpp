#include <iostream>

using namespace std;

/*
디버깅 모드 >> 호출 스택에서 함수가 쌓이는 것을 볼 수 있음
stack overflow 메모리가 초과됨


특정 함수에서는 더 이상 호출하지 않도록 해야함
같은 함수라도 구분할 수 있는 방법
1. 매개변수
2. 전역변수
*/

void func1() {
	cout << "1\n";
	func1();
}

int main()
{

	func1();
	return 0;
}