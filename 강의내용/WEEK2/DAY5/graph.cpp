#include <iostream>
#include <vector>

using namespace std;

/*

5 4 <- node개수, edge개수
1 2 <- edge정보(from to)
1 3 <- edge정보(from to)
1 4 <- edge정보(from to)
2 5 <- edge정보(from to)

*/

int main()
{
	/*

	// 1. 인접 행렬

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	int adj[6][6] = { 0 };
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}


	// 특정 from에서 갈 수 있는 모든 to찾기
	int node = 1;
	for (int to = 1; to <= 5; to++)
	{
		if (adj[node][to] == 0) continue;
		// 갈 수 있는 점이다.
		cout << to << ' ';
	}

	*/

	// 2. 인접 리스트

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	vector<int> v[6];	// v[from] : from에서 갈 수 있는 to 들을 저장한 vector
	// vector<저장할 data형태> v;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);	// vector의 맨 뒤에 공간을 추가해서 value라는 값을 저장
	}

	// 특정 from에서 갈 수 있는 모든 to찾기
	int node = 1;
	for (int i = 0; i < v[node].size(); i++)
		//vector.size() : vector가 갖고있는 data 개수
	{
		int to = v[node][i];
		cout << to;
	}

	return 0;
}