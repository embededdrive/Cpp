#include <iostream>
#include <algorithm>

using namespace std;

/*

거스름돈 예시

1200 4
100 50 10 500

*/

bool cmp(int left, int right) {
	if (left > right)
		return true;
	if (left < right)
		return false;
	return false;
}

int target;
int N;

int coins[5];

int main()
{
	cin >> target;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> coins[i];

	// S : 탐욕적으로 가장 큰 단위의 동전부터 줄여준다!
	sort(coins, coins + N, cmp);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int now = coins[i];
		ans += target / now;
		target %= now;
	}

	cout << ans;

	return 0;
}