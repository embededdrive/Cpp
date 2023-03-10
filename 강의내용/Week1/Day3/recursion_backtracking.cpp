#include <iostream>
#include <cstring>

using namespace std;

char path[10];
int used[10];	//DAT

void run(int lev)
{
	if (lev == 3)
	{
		cout << path << endl;
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		if (used[i] == 1) continue;	// 검사해보기
		
		used[i] = 1;				// 들어가면서 used에 체크
		path[lev] = '0' + i;
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;				// 갔다오면서 지워준다
	}

}

int main()
{
	run(0);

	return 0;
}