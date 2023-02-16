#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 11

*/

struct Edge
{
	int a;
	int b;
	int cost;
};

bool cmp(Edge left, Edge right) {
	if (left.cost < right.cost)
		return true;
	if (left.cost > right.cost)
		return false;
	return false;
}

int N, M;		// 노드의 개수, 간선의 개수
vector<Edge> v;	// 간선을 모두 저장하는 벡터
int parent[100];

int Find(int now) {
	if (now == parent[now])
		return now;

	return parent[now] = Find(parent[now]);
}

void uunion(int A, int B) {
	int pa = Find(A);
	int pb = Find(B);

	if (pa == pb)
		return;

	parent[pb] = pa;
}

int kruskal() {
	sort(v.begin(), v.end(), cmp);

	// MST의 완성 여부 확인 -> 최종적으로 모든 간선을 확인했을 때
	// 총 N - 1개의 간선이 연결되었는지를 확인해야 한다
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		Edge now = v[i];

		if (Find(now.a) == Find(now.b))
			continue;

		if (now.cost < 10)
			continue;
		
		// ** 추가 -> 1개의 간선을 더 연결했다
		cnt++;
		sum += now.cost;
		uunion(now.a, now.b);
	}

	// MST가 완성되었는지를 확인
	// 최종적으로 연결된 간선의 개수 = N - 1개라면 OK
	if (cnt + 1 == N)
		return sum;
	else
		return 0;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		v.push_back({ from, to, cost });
	}

	for (int i = 0; i < N; i++)
		parent[i] = i;

	int ret = kruskal();

	if (ret)
		cout << ret;
	else
		cout << "만들 수 없다";

    return 0;
}