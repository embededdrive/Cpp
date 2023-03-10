#include <iostream>

using namespace std;

// N 번째 피보나치를 구하는 프로그램
int fibo(int now) {
	// 기저조건
	if (now <= 2)
		return 1;

	// 재귀 구성
	return fibo(now - 1) + fibo(now - 2);
}

int main()
{
	int N;

	cin >> N;

	cout << fibo(N);

	return 0;
}