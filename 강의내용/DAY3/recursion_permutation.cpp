#include <iostream>

using namespace std;

char path[3];

void run(int lev, int start)
{
	if (lev == 2)
	{
		cout << path << endl;
		return;
	}

	for (int i = start; i <= 6; i++)
	{
		path[lev] = '0' + i;
		run(lev + 1, i);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 1);

	return 0;
}