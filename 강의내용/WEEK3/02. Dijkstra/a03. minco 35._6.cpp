#include <iostream>
#include <queue>

using namespace std;
int main()
{
	int mid = 500, n;

	priority_queue<int, vector<int>, less<int>> left_heap;
	priority_queue<int, vector<int>, greater<int>> right_heap;

	cin >> n;

	int de = -1;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (b < a)
			swap(a, b);

		if (a < mid && mid < b)
		{
			left_heap.push(a);
			right_heap.push(b);
		}
		else if (b <= mid)
		{
			left_heap.push(a);
			left_heap.push(b);
			right_heap.push(mid);
			mid = left_heap.top();
			left_heap.pop();
		}
		else if (mid <= a)
		{
			right_heap.push(a);
			right_heap.push(b);
			left_heap.push(mid);
			mid = right_heap.top();
			right_heap.pop();
		}

		cout << mid << '\n';
	}

	return 0;
}