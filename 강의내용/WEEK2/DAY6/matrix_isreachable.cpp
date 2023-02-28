#include <iostream>

using namespace std;

int adj[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];
int cnt = 0;

void run(int now) {
	// cout << now;
	if (now == 3)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (adj[now][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		run(i);
		// used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	run(0);

	if (cnt != 0) cout << 'O';
	else cout << 'X';

	return 0;
}