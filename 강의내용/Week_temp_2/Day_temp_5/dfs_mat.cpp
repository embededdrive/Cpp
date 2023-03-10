#include <iostream>
#include <vector>

using namespace std;

int nodeCnt, edgeCnt;
int adj[6][6] = { 0 };

void dfs(int now)
{
	// 지금 now라는 점에 도착했다!

	// 2. 기저조건(option)

	for (int to = 0; to <= nodeCnt; to++)
	{
		// 가지치기(가능한지 판별)과 기능적으로 유사
		if (adj[now][to] == 0) continue; // now -> to로 갈 수 없으면 무시

		cout << now << "에서" << to << "로 갑니다!\n";
		// 1. 재귀 기본 구조
		dfs(to);
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	/*
	// 특정 from에서 갈 수 있는 모든 to찾기
	int node = 1;
	for (int to = 1; to <= 5; to++)
	{
		if (adj[node][to] == 0) continue;
		// 갈 수 있는 점이다.
		cout << to << ' ';
	}
	*/
	dfs(1);

	return 0;
}