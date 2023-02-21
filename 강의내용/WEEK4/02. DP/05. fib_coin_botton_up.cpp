#include <iostream>

using namespace std;

/*

1200 5
10 50 100 400 500

*/

int dp[10001];
int target;
int N;
int coins[100];

int main()
{
	cin >> target >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];
	
	// Bottom-Up
	// #0. 최소값
	for (int i = 0; i <= target; i++)
		dp[i] = 21e+08;

	// 찾을 수 있는 가장 작은 문제에 대한 해답
	dp[0] = 0;

	// 모든 코인에 대해서 테이블을 채운다
	for (int i = 0; i < N; i++)
	{
		int now = coins[i];
		for (int j = now; j <= target; j++)
		{
			// 지금 위치에서 내 동전의 값만큼을 뺀 공간에서
			// 동전을 하나 더 추가했을때 -> 지금 now를 만들 수 있는 값이 나온다
			// 이미 dp에 기록된 값보다 많은 개수로 만들게 된다면 -> 갱신 X
			if (dp[j - now] + 1 < dp[j])
				dp[j] = dp[j - now] + 1;
		}
	}
	
	cout << dp[target];

	return 0;
}