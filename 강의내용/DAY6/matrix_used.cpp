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
		used[i] = 0;
		// used[i] = 0 을 안하면 : 연결된 노드를 1회씩만 모두 탐색한다.
		// 갈 수 있는지?
		// used[i] = 0 을 하면 : 모든 경로를 탐색한다
		// 길이 몇개인지?
	}
}

int main()
{
	used[0] = 1;
	run(0);

	cout << cnt;

	return 0;
}