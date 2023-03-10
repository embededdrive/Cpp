#include <iostream>

using namespace std;

int parent[10];

int Find(int now)
{
	if (now == parent[now])
	{
		return now;
	}

	int ret = Find(parent[now]);

	return ret;
}

int main()
{

	for (int i = 1; i <= 7; i++)
	{
		parent[i] = i;
	}

	parent[1] = 7;
	parent[2] = 7;
	parent[3] = 2;
	parent[4] = 5;
	parent[5] = 2;

	cout << Find(7) << '\n';
	cout << Find(3) << '\n';
	cout << Find(2) << '\n';
	cout << Find(5) << '\n';

	return 0;
}