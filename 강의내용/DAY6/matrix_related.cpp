#include <iostream>

using namespace std;

int adj[4][4] = {
	0, 1, 0, 1,
	0, 0, 0, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
}, nodes[4] = {15, 99, 88, -77};

int main()
{
	int n, related[4], cnt = 0;

	cin >> n;


	for (int i = 0; i < 4; i++)
	{
		if (adj[n][i] == 1)
		{
			related[cnt++] = i;
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		cout << nodes [related[i]] << ' ';
	}

	return 0;
}