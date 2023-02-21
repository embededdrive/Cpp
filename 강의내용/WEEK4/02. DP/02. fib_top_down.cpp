#include <iostream>

using namespace std;

int dp[101];

// N 번째 피보나치를 구하는 프로그램
int fibo(int now) {
	// 기저조건
	if (now <= 2)
		return 1;

	// 내 기억속에서 now에 대한 문제를 기억하고 있다면
	if(dp[now] != 0)
		return dp[now];

	// 재귀 구성
	// 다시 여기까지 돌아오는 순간
	// now 까지의 정답을 찾았다
	// now 번째의 정답을 아니까 -> 잊지 않도록 기억(기록)
	return dp[now] = fibo(now - 1) + fibo(now - 2);
}

int main()
{
	int N;

	cin >> N;

	cout << fibo(N);

	return 0;
}