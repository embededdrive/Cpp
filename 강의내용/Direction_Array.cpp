#include <iostream>

using namespace std;

int main()
{
	int M[3][5] = { 0 };
	int row, col;

	cin >> row >> col;

	int dr[4] = {-1, 1, 0, 0};	// row쪽에 더해질 값
	int dc[4] = {0, 0, -1, 1};	// col쪽에 더해질 값
	
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];	// row에서 i번째 방향
		int nc = col + dc[i];	// col에서 i번째 방향
		if (0 > nr || 0 > nc || nr >= 3 || nc >= 5) continue;
		
		M[nr][nc] = 1;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << M[i][j];
		}
		cout << endl;
	}

	return 0;
}