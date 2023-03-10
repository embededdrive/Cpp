#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*

10 13
0 1 1
0 3 4
0 2 5
1 4 3
1 5 6
2 5 8
2 7 10
2 6 9
7 6 11
6 9 2
6 8 13
7 8 12
5 6 7

*/

int N, M;

struct Edge {
	int to;
	int cost;
	bool operator < (Edge next) const {
		// 내가 원하는 상황
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;

		return false;
	}
};

vector<Edge> al[100];

void dijkstra(int start)
{
	// [준비단계]
	// 1. priority queue 준비
	priority_queue<Edge> pq;

	pq.push({ start, 0 });

	// 2. dist 준비
	int dist[100] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i < N; i++)
		dist[i] = MAX;
	dist[start] = 0;

	// 3. visited 준비
	int visited[100] = { 0, };

	// [구현단계]
	// 1. 더 이상 갈 후보지가 없을 때까지 반복
	while (!pq.empty())
	{
		// 2. 후보지 중 가장 가중치가 낮은 간선을 뽑아옵니다.
		// priority queue -> cost를 기준으로 MINHEAP

		Edge now = pq.top();
		pq.pop();

		// 이미 확정된 노드라면 이 노드에 대해서는 아무것도 안해도 된다!
		if (visited[now.to] == 1)
			continue;
		// now까지의 최단거리 확정된다!
		visited[now.to] = 1;

		// 3. now로 부터 갈 수 있는 간선들을 확인
		for (int i = 0; i < al[now.to].size(); i++)
		{
			Edge next = al[now.to][i];
			// ncost = next번까지의 최종 비용
			int ncost = dist[now.to] + next.cost;
			// 만약 지금 최종 비용이 이미 기록되어있는 후보 경로의 비용보다 크거나 같으면
			if (dist[next.to] <= ncost)
				continue;					// 쓸모없는 경로
			// next까지 가기위한 새로운 최단거리 찾음!~

			dist[next.to] = ncost;
			// 새로운 후보지로 등록
			pq.push({ next.to, ncost });
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		al[from].push_back({to, cost});
		al[to].push_back({ from, cost });
	}

	dijkstra(0);

	return 0;
}