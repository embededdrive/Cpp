#include <iostream>
#include <algorithm>

// 민코딩 그리디 #5

using namespace std;

struct Node
{
	int startTime;
	int endTime;
};

bool cmp(const Node& left, const Node& right)	// left / right 의 값을 바꾸지 말되 참조
{
	return left.endTime < right.endTime;
}

int main()
{
	int n;
	Node arr[100000];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].startTime >> arr[i].endTime;
	}

	sort(arr + 0, arr + n, cmp);	// [begin, end)

	int prev = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(prev <= arr[i].startTime)) continue;
		cnt++;
		prev = arr[i].endTime;
	}
	cout << cnt;

	return 0;
}