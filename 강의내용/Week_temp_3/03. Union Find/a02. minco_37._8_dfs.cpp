#include <iostream>

using namespace std;

int map[101][101];
int visited[101][101];

int N, M, cnt;

void dfs(int cY, int cX)
{
	int dY[4] = {-1, 1, 0, 0};
	int dX[4] = {0, 0, -1, 1};

	for (int i = 0; i < 4; i++)
	{
		int posY = cY + dY[i];
		int posX = cX + dX[i];

		if (posY < 0 || posX < 0 || posY >= N || posX >= M) continue;
		if (map[posY][posX] == 0) continue;
		if (visited[posY][posX] == 1) continue;

		visited[posY][posX] = 1;
		dfs(posY, posX);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) continue;
			if (visited[i][j] == 1) continue;
			cnt++;
			dfs(i, j);
		}
	}

	cout << cnt;

	return 0;
}