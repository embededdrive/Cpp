#include <iostream>

using namespace std;

int path[2];
void run(int lev)
{
	if (lev == 2)
	{
		cout << path[0] << path[1] << '\n';
		return;
	}

	/*

	하향	/	방향에서만 실행

	*/

	for (int i = 0; i < 3; i++)
	{
		/*

		함수가 시작할때마다 실행

		*/

		path[lev] = 1 + i;	// 적고 재귀타기
		run(lev + 1);
		path[lev] = 0;		// 적은거 지우기

		/*

		함수가 끝날때마다 실행

		*/
	}

	/*

	상향 ＼	방향에서만 실행

	*/
}

int main()
{
	run(0);

	return 0;
}