﻿#include <iostream>
#include <vector>

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
};

vector<Edge> al[100];

void dijkstra(int start)
{
	int dist[100] = { 0 };
	int MAX = 21e8;
	for (int i = 0; i < N; i++)
		dist[i] = MAX;

	dist[start] = 0;

	// visited 준비
	// index : 노드, value : 

	int visited[100] = { 0, };

	// dijkstra 동작을 구현
	// 노드의 개수만큼 반복 -> 한번 돌 때마다 하나의 노드의 최단거리가 확정
	// 즉 모든 노드의 최단거리가 확정될 때까지
	for (int i = 0; i < N; i++)
	{
		int mincost = 21e8;
		int now = -1;

		// 지금 가장 가중치가 작은 간선을 찾을 것
		for (int j = 0; j < N; j++)
		{
			// j번째 노드에 기록된 후보지가 최소값보다 작으면 갱신
			if (dist[j] >= mincost)
				continue;
			// 이미 확정된 노드라면 -> 다시 갈 필요 X
			if (visited[j] == 1)
				continue;
			// 새로운 최소값을 찾았다!
			mincost = dist[j];
			now = j;
		}

		// now 까지의 최단거리는 확정
		visited[now] = 1;

		for (int j = 0; j < al[now].size(); j++)
		{
			Edge next = al[now][j];
			// 다음 노드까지의 비용 = 지금 확정된 노드까지의 비용(거리) + next 까지 가는 비용
			int ncost = dist[now] + next.cost;
			// 새로운 경로를 찾았다
			// 하지만, 이미 기록된 후보지보다 더 오래걸리는 경로면 쓸모 없다.
			if (dist[next.to] <= ncost)
				continue;					// 새로운 후보지로 등록하지 않는다.
			dist[next.to] = ncost;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << i << " 까지의 최단거리 : " << dist[i] << '\n';
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