#include <iostream>

using namespace std;

/*

9개의 노드, 6개의 결합 정보
9 7
0 3
3 6
6 8
3 7
1 4
2 5
0 1

*/

// Find : 소속을 찾아가는 알고리즘
// #1. 정보 (부모 정보)를 저장할 parent가 필요

int parent[100];
int N, M;

int Find(int now)
{
	if (now == parent[now])
		return now;

	return parent[now] = Find(parent[now]);
}

void Union(int A, int B)
{
	// #1. 각 A와 B의 소속을 확인
	int pa = Find(A);
	int pb = Find(B);

	// #2. B의 소속을 A의 소속의 산하로 만든다!
	parent[pb] = pa;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int A, B;

		cin >> A >> B;
		Union(A, B);
	}

	int a, b;
	cin >> a >> b;
	// a와 b가 같은 그룹인가?
	// 현재 parent의 상황으로 비교 X
	// 한번 더 업데이트

	// A의 대표를 다시 한번 찾아가면서 parent를 update
	// A의 상위 노드에 대한 path compression
	// if (parent[a] == parent[b])
	if (Find(a) == Find(b))
		cout << "같은 그룹";
	else
		cout << "다른 그룹";


	return 0;
}