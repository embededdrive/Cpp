#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Edge {
	int node;
	int cost;
};

struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용 
};

struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost;
	}
};

int N, T;
vector<Edge> adj[8];

void input() {
	cin >> N >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ b,cost });
	}

}

const int INF = 1e9;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	// 일반 dijkstra
	// [준비단계]
	priority_queue<Node, vector<Node>, cmp> pq;
	int processed[8] = { 0 };
	int start = 1;

	// 시작노드를 접근가능한 가장 가까운 노드로 저장
	pq.push({ start, 0 });

	// dist 배열을 최소비용 저장용으로 사용
	int dist[8];
	
	// dist 배열을 비교용으로도 사용하기 위해 초기화
	dist[start] = 0;
	for (int i = 1; i <= 7; i++) dist[i] = INF;

	// [구현단계]
	while (!pq.empty())
	{
		// pq에는 접근가능한 가장 가까운 노드가 먼저 출력됨
		Node now = pq.top();
		pq.pop();

		// 이미 계산된 최소비용보다 클 경우
		if (now.accCost > dist[now.node]) continue;

		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost;

			// 최소비용보다 큰 비용을 가진 노드는 추가하지 않는다
			if (dist[next.node] <= newCost) continue;
			dist[next.node] = newCost;

			pq.push({ next.node, newCost });
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
	}
	return 0;
}