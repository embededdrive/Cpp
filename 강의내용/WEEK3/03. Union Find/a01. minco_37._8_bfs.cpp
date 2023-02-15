#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];

int N, M, cnt;

struct Node {
	int cY, cX;
};

void bfs(int i, int j)
{
	int dY[4] = { -1, 1, 0, 0 };
	int dX[4] = { 0, 0, -1, 1 };

	queue<Node> q;

	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int posY = now.cY + dY[i];
			int posX = now.cX + dX[i];

			if (posY < 0 || posX < 0 || posY >= N || posX >= M) continue;
			if (visited[posY][posX] == 1) continue;
			if (map[posY][posX] == 0) continue;

			visited[posY][posX] = 1;
			q.push({ posY, posX });
		}
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
			bfs(i, j);
		}
	}

	cout << cnt;

	return 0;
}