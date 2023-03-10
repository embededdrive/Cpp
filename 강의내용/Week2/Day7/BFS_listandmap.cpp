#include <iostream>
#include <queue>

using namespace std;

int n;  // 노드의 개수
int m;  // 간선의 개수

/*

4 5
0 1
0 2
1 2
1 3
2 3

*/

int mat[10][10];	// 인접 행렬
vector<int> al[10];	// 인접리스트

// BFS
// # 1. queue 준비
// ---> 시작 노드 queue에 삽입

// # 2. (cycle이 생길 시) visited 준비;
// --> 시작 노드를 예약 후 시작

// # 3. BFS 동작
// ---> now -> 지금 방문하는 노드를 queue의 맨 앞에서 빼옵니다.
// ---> now에서 갈 수 있는 노드들을 판단하여, 갈 수 있다면, queue에 새로 삽입

// DFS와 BFS의 시간복잡도
// 일반적인 완전 탐색 : 
// -> 인접 행렬 : O(V^2)		-> V (노드의 개수)	노드에 비해 간선이 매우 많을때 유리
// -> 인접 리스트 : O(V + E)

// DFS -> backtracking
// 재귀의 시간 복잡도 O(2^N) ~ O(N!)

// Upgrade -> BFS 최단경로 알고리즘
// visited에 시작노드로부터 모든 노드까지의 최단 경로 기록
void bfsMat(int start) {
	// # 1. queue 준비
	queue<int> q;
	// queue에 시작 노드 삽입
	q.push(start);

	// # 2. visited 준비
	int visited[10] = { 0 };
	//시작 노드를 방문 처리
	visited[start] = 1;

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

			// 만약 이미 예약되어있거나 / 방문한 노드라면 -> 예약을 걸지 않겠다
			// if (visited[next] == 1) continue;

			// 내가 이미방문했는가?
			if (visited[next] != 0)
				continue;

			// next번 노드에 갈 수 있따! queue에 삽입
			q.push(next);
			// 단순히 그냥 완전 탐색 -> 그러면 (0, 1)로 왔다 안왔다만 기록 해도 됨
			// visited[next] = 1;

			// 지금 내가 예약하려고 하는 next까지의 경로 = now 까지 온 경로에서 한번 더 움직인다!
			visited[next] = visited[now] + 1;
		}
	}

	cout << '\n';

	//start로부터 모든 경로의 값을 출력
	for (int i = 0; i < n; i++)
	{
		cout << i << "까지의 최단경로 : " << visited[i] - 1 << '\n';
	}
}

void bfsList(int start) {
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

		// 단방향 연결
		mat[from][to] = 1;
		al[from].push_back(to);
		// 양방향 연결
		mat[to][from] = 1;
		al[to].push_back(from);
	}

	// BFS : 재귀적으로 동작 X
	// 함수로 만들 필요 X
	// bfs(시작 노드)

	bfsMat(0);
	//bfsList(0);

	return 0;
}