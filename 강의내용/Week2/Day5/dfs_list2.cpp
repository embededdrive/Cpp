#include <iostream>
#include <vector>

using namespace std;

vector<int> v[8];	// v[from] : from에서 갈 수 있는 to 들을 저장한 vector


int used[8];
// used, visited
// 갔던 점인지 판별
// used[node번호= = 해당 node를 들렀었는가?

vector<int> path;
// 1 -> 5 까지 어떤 경로롤 갈 수 있는가?

void dfslist(int now)
{
	// 2. 기저조건 (option)
	if (now == 7)
	{
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
		// now -> to 찾기
	{
		int to = v[now][i];
		
		// 4. 가지치기(판별)
		if (used[to] == 1) continue;

		// 3. 기록 및 처리
		cout << now << "에서" << to << "로 갑니다!\n";

		used[to] = 1;
		path.push_back(to);

		// 1. 재귀 기본 구조
		dfslist(to);

		path.pop_back();	// vector.pop_back() : vector의 맨 뒤 data를 메모리까지 '삭제'
		used[to] = 0;
		// used를 다시 복구 : 실제 경로랑 완벽하게 일치
		// used를 다시 복구x : 단순하게 모든 점들을 정확히 1번씩만 들러볼 때
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
	path.push_back(1);
	dfslist(1);

	return 0;
}