#include <iostream>

using namespace std;

char path[10];

void run(int lev, int sum)
{
	/*
	
	가지치기 1번 방법
	if (sum > 10) return;
	코드가 보기 편한 방법으로 택1

	*/

	if (lev == 3)
	{
		cout << path << " = " << sum << '\n';
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		/*
		
		가지치기 2번 방법
		if (sum + i > 10) continue;

		*/
		
		path[lev] = '0' + i;
		run(lev + 1, sum + i);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 0);

	return 0;
}