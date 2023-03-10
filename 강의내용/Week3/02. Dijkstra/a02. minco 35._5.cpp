#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue<long long, vector<long long>, greater<long long>> pq; // minheap
	// 1st ~ 1500th ugly number 기록하기 
	int order[1501];
	int th = 1;
	long long prev = -1; // 바로 직전에 뽑힌값
	pq.push(1);
	while (th <= 1500)
	{
		long long now = pq.top(); pq.pop();
		if (prev == now) continue;
		// process
		order[th] = now;
		th++;
		prev = now;
		pq.push(now * 2);
		pq.push(now * 3);
		pq.push(now * 5);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int th;
		cin >> th;
		cout << order[th] << " ";
	}
	return 0;
}



