#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;  // 노드의 개수
int m;  // 간선의 개수

/*
7 6
0 1
0 2
1 3
1 4
4 5
4 6
*/

int list[7];

vector<int> al[10];	// 인접리스트


void bfs(int start) {
	// # 1. queue 준비
	queue<int> q;
	q.push(start);

	// # 2. bfs 동작
	while (!q.empty()) 
	{
		int now = q.front();
		q.pop();

		cout << now << ' ';

		for (int i = 0; i < al[now].size(); i++)
		{
			int next = al[now][i];
			q.push(next);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;

		cin >> from >> to;

		mat[from][to] = 1;
		al[from].push_back(to);
	}

	// 인접 리스트 bfs
	bfs(0);

	return 0;
}