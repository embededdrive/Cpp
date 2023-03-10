#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int weight;
	bool isGold;
};

// pq 에서만 비교할때 사용
struct cmp
{
	// function operator 연산자 오버로딩
	bool operator()(Node& left, Node& right)
	{
		if (left.weight != right.weight)
		{
			return left.weight > right.weight;
		}
		if (left.isGold == false && right.isGold == true)
			return true;
		return false;
	}
};

int main()
{
	int n;
	cin >> n;

	priority_queue<Node, vector<Node>, cmp> pq;
	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		pq.push({ weight, true });
	}

	int cnt = 0;
	while (true)
	{
		Node first = pq.top();
		pq.pop();
		if (first.isGold == false) break;
		cnt++;

		Node second = pq.top();
		pq.pop();
		if (second.isGold == false) break;
		cnt++;

		pq.push({ 2 * second.weight, false });
	}

	cout << cnt;

	return 0;
}