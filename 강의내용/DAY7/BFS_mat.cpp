#include <iostream>
#include <queue>

using namespace std;

int n;  // 노드의 개수
int m;  // 간선의 개수

int mat[10][10];	// 인접 행렬

// BFS
// # 1. queue 준비
// ---> 시작 노드 queue에 삽입

// # 2. BFS 동작
// ---> now -> 지금 방문하는 노드를 queue의 맨 앞에서 빼옵니다.
// ---> now에서 갈 수 있는 노드들을 판단하여, 갈 수 있다면, queue에 새로 삽입

void bfs(int start) {
	// # 1. queue 준비
	queue<int> q;
	// queue에 시작 노드 삽입
	q.push(start);

	// BFS 동작 -> queue에 예약된 / 가야되는 노드가 있는 동안
	while (!q.empty()) {
		// # 1. 대기열에서 맨 앞의 노드를 방문
		int now = q.front();	// now : 내가 지금 방문하고 있는 노드
		// queue에서는 삭제
		q.pop();
		// # 2. 갈 수 있는 노드들을 판단하고 큐에다가 삽입
		// 큐에 삽입 -> 미래에 갈 노드를 확정 (미리 예약)

		cout << now << ' ';

		for (int next = 0; next < n; next++)
		{
			// 만약 now -> next로 갈 수 없다면 continue;
			if (mat[now][next] == 0) continue;

			// next번 노드에 갈 수 있따! queue에 삽입
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
	}

	// BFS : 재귀적으로 동작 X
	// 함수로 만들 필요 X
	// bfs(시작 노드)

	bfs(0);

	return 0;
}