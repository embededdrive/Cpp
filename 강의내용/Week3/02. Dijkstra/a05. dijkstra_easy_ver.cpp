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

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	// 가짜 dijkstra 
	// [준비단계]
	priority_queue<Node, vector<Node>, cmp> pq;
	int processed[8] = { 0 };
	int start = 1;

	// 시작노드를 접근가능한 가장 가까운 노드로 저장
	pq.push({ start, 0 });

	// dist 배열을 최소비용 저장용으로 사용
	int dist[8] = { 0 };

	// [구현단계]
	while (!pq.empty())
	{
		// pq에는 접근가능한 가장 가까운 노드가 먼저 출력됨
		Node now = pq.top();
		pq.pop();

		// 해당노드를 최소비용으로 확정
		if (processed[now.node] == 1) continue;
		processed[now.node] = 1;

		// 최소비용 저장
		dist[now.node] = now.accCost;

		// 최소비용으로부터 접근가능한 모든 노드 pq에 추가
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost;
			pq.push({ next.node, newCost });
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
	}
	return 0;
}