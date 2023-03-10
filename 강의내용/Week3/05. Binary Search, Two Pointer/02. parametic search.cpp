#include <iostream>

using namespace std;

int N, arr[4];
int MAX;

bool condition(int val) {
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > val)
			sum += val;		// 상한선 만큼 밖에 줄 수 없어
		else
			sum += arr[i];
	}
	if (sum > MAX)
		return false;
	return true;
}

void psearch(int low, int high)
{
	int left = low;		// 상한선 범위의 가장 낮은 값
	int right = high;	// 상한선 범위의 가장 큰 값 = 내가 가진 전부
	int ans;
	while (left <= right)
	{
		// mid : 가능성 -> 정답이라고 가정한 값
		int mid = (left + right) / 2;
		// 이 가능성이 정답이 될 수 있어?
		if (condition(mid) == true) {
			// 정답이 될 가능성이 있는 값을 찾았다
			ans = mid;
			// 더 많은 금액을 줄 수 있는가?
			// 더 상한선을 높게 잡아도 가능한가?
			left = mid + 1;
		}
		else {
			// 이 값이 정답이 될 수 없어
			// 너무 상한선을 높게 잡았다
			// 상한선의 가장 큰 값의 범위를 낮춘다
			right = mid - 1;
		}
	}

	cout << ans;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >>  MAX;
	psearch(0, MAX);

	return 0;
}