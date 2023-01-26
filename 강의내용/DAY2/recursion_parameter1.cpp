#include <iostream>

using namespace std;

/*
같은 함수라도 구분할 수 있는 방법
1. 매개변수
*/

void func1(int a) {
	// 다음 함수에서는 내가 갖고 있던 a 보다 1개 더 큰 값으로 사용해라
	cout << a;
	if (a == 10)
	{
		return;
	}
	func1(++a);
}

int main()
{
	func1(0);
	return 0;
}