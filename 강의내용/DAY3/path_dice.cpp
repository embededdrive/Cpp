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

void func(int lev)
{
	// 지금 a 번째 주사위 눈을 뽑을 차례

	// 2. 기저조건
	// 0 ~ N-1 번 주사위까진 정상
	// N번 주사위부터는 존재하지 않는 주사위
	if (lev >= N)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << path[i] << ' ';
		}
		cout << endl;
		return;
	}

	// i : 1 ~ 6 이라는 눈
	for (int i = 1; i <= 6; i++)
	{
		// 3. 기록 및 처리
		path[lev] = i;

		// 1. 재귀 기본 구조
		// a + 1 번째 주사위에서 눈을 뽑으러 가라!
		func(lev + 1);
	}
}

int main()
{
	cin >> N;

	func(0);

	return 0;
}