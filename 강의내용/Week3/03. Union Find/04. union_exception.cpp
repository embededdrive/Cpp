#include <iostream>

using namespace std;

/*

6개의 노드, 5개의 결합 정보
6 5
10 20 30 40 50 60
0 1
3 0
3 4
4 3
2 5

*/

int parent[100];
int pop[100];
int N, M;

int Find(int now)
{
	if (now == parent[now])
		return now;

	return parent[now] = Find(parent[now]);
}

void Union(int A, int B)
{
	int pa = Find(A);
	int pb = Find(B);

	// # 2. 만약 A와 B가 이미 같은 소속이라면 아래 합병을 거치지 마라
	if (pa == pb)
		return;

	parent[pb] = pa;

	pop[pa] += 10;
	pop[B] -= 10;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
		cin >> pop[i];

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		// Union을 하기 전에, 이런 문제에서는 이미 결합된 소속을 다시 결합하면 문제가 생길 수 있다
		// #1. Union을 하기전에 결합여부 확인
		if (Find(A) == Find(B))
			continue;
		Union(A, B);
	}

	for (int i = 0; i < N; i++)
	{
		cout << pop[i] << ' ';
	}


	return 0;
}