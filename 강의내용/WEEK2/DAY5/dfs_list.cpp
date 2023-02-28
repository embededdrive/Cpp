#include <iostream>
#include <vector>

using namespace std;

vector<int> v[6];	// v[from] : from에서 갈 수 있는 to 들을 저장한 vector


int used[6];
// used, visited
// 갔던 점인지 판별
// used[node번호= = 해당 node를 들렀었는가?

void dfslist(int now)
{
	for (int i = 0; i < v[now].size(); i++)
		// now -> to 찾기
	{
		int to = v[now][i];
		if (used[to] == 1) continue;

		cout << now << "에서" << to << "로 갑니다!\n";

		dfslist(to);
	}
}

int main()
{
	// 2. 인접 리스트

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	
	// vector<저장할 data형태> v;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);	// vector의 맨 뒤에 공간을 추가해서 value라는 값을 저장
	}

	used[1] = 1;
	dfslist(1);

	return 0;
}