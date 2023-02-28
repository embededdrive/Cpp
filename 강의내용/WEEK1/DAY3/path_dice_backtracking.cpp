/*

주사위 게임
-> 나올 수 있는 모든 경우

입력 : 정수 1개 (주사위 개수)
출력 : 해당 주사위들로 나올 수 있는 주사위 눈의 모든 경우

*/

#include <iostream>

using namespace std;

int N;

int path[3];
// 주사위번째, 눈

int visited[7];	// index : 주사위 눈, value : 해당 주사위 눈을 뽑았었는가?
// visited , used를 이름으로 많이 사용

int sum;		// 그렇게 뽑은 주사위 눈의 합

void func(int lev)
{	// 2. '기저조건'
	if (lev >= N)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << path[i] << ' ';
		}
		cout << "sum : " << sum;
		cout << endl;
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		// 4. '가지치기' (내가 지금 하려는 선택이 괜찮은가?) [backtracking]
		if (visited[i] == 1)
			continue;

		// 3. '기록 및 처리'
		path[lev] = i;		// lev 번째 주사위에서 i라는 눈을 뽑았다.
		visited[i] = 1;		// i라는 눈은 뽑혔다.
		sum += i;

		// 4. <-- 여기서 판단해봐야 하는 경우도 있음

		// 1. '재귀 기본 구조'
		func(lev + 1);

		// i라는 눈을 뽑아서 진행하는 과정이 모두 끝났다.

		// 3. '기록 및 처리'의 복구
		// i라는 눈은 사용이 끝났으므로 그에 따른 기록을 삭제
		visited[i] = 0;	// i라는 눈에 대한 기록 삭제
		path[lev] = 0;	// a번째 주사위에서 i라는 눈을 뽑은 기록 삭제
		sum -= i;
	}
}

int main()
{
	cin >> N;

	func(0);

	return 0;
}