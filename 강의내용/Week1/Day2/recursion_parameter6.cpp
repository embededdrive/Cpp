#include <iostream>

using namespace std;

char path[10];
int cnt = 0;

void run(int lev, int gop)
{
	if (lev == 3)
	{
		if (gop % 2 == 0) cnt++;
		cout << path << " " << gop << '\n';
		return;
	}

	for (int i = 2; i <= 4; i++)
	{
		path[lev] = i + '0';
		run(lev + 1, gop * i);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 1);
	cout << cnt;

	return 0;
}