#include <iostream>

using namespace std;

int arr[4][4] = {
	3, 1, 4, -2,
	1, 1, -1, 1,
	2, 3, 1, 4,
	5, 1, 0, -3
};

int maxi = -21e8;
int mini = 21e8;

void run(int lev, int gop)
{
	if (lev == 4)
	{
		if (maxi < gop) maxi = gop;
		if (mini > gop) mini = gop;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		run(lev + 1, gop*arr[lev][i]);
	}
}

int main()
{
	run(0, 1);
	cout << maxi;
	cout << mini;


	return 0;
}