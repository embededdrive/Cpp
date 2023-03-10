#include <iostream>

using namespace std;

// 지역변수 : 함수 안에서 만든 변수 (RAM - stack)
// 전역변수 : 함수 바깥에서 만든 변수 (heap)
int a = 3;

void func1() {
	a = 10;
	int b = 10;

	cout << a << " " << b << '\n';
}

void func2() {
	a = 7;
	int b = 7;
	cout << a << " " << b << '\n';
	func1();
	cout << a << " " << b << '\n';
}

int main()
{
	int b = 5;
	cout << a << " " << b << '\n';
	func2();
	cout << a << " " << b << '\n';
	return 0;
}