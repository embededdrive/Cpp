#include <iostream>

using namespace std;

int adj[6][6] = {
	0, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};

char value[7] = {"ABTRVG"};

void run(int now)
{
	cout << now << '\n';
	for (int to = 0; to < 6; to++)
	{
		if (adj[now][to] == 0) continue;
		run(to);
	}
}

int main()
{
	run(0);

	return 0;
}