#include <iostream>

using namespace std;

char arr[10];

void run(int lev)
{
	if (lev == 4)
	{
		cout << arr << '\n';
		return;
	}

	for (int i = 'A'; i <= 'Z'; i++)
	{
		arr[lev] = i;
		run(lev + 1);
		arr[lev] = 0;
	}
}

int main()
{
	run(0);

	return 0;
}