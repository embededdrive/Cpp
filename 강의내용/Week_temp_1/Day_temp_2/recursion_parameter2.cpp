#include <iostream>

using namespace std;

void func1(int a) {
	if (a == 10)	// 2. 끝낼 조건 (기저조건)
	{
		/*
			끝내면서 처리
		*/
		cout << "끝! ";

		return;		// <- 바로 끝내라
	}


	/*
	3-1
	함수들을 진행해 나가면서 처리
	다음 함수로 가기 전
	*/
	cout << a << ' ';

	func1(a + 1);	// 1. 현재 함수에서 다음 함수로 진행 (재귀의 기본 구조)

	/*
	3-2
	함수들을 되돌아 오면서 처리
	다음 함수를 갔다온 후
	*/
	cout << a << ' ';
}

int main()
{
	func1(0);
	return 0;
}