#include <iostream>

using namespace std;

int dp[10001];
int target;
int N;
int coins[100];

int func(int now) {
	// 기저 조건
	if (now == 0)
		return 0;
	if (now < 0)
		return 21e+08;

	// 만약 now에 대한 답이 기억되고 있다면
	if (dp[now] != 0)
		return dp[now];

	// 재귀 구성
	// now에서 모든 동전을 하나씩 빼가면서 쭉 내려가본다
	int MIN = 21e+08;
	for (int i = 0; i < N; i++)
	{
		// now로 다시 올라오면
		// func(now - coins[i]) + 1
		int temp = func(now - coins[i]) + 1;
		if (temp < MIN)
			MIN = temp;
	}

	// now까지 올라왔을 때, 하위 문제의 답을 모두 취합하여
	// 그 중 가장 작은 답을 dp[now]에 기록
	return dp[now] = MIN;
}

int main()
{
	cin >> target >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];
	

	cout << func(target);

	return 0;
}