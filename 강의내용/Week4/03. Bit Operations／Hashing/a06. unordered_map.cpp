#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int nums[3][3] = {
	15, 11, -7,
	55, -7, 11,
	-7, -55, -9
};

struct Coord {
	int y, x;
};

unordered_map<int, vector<Coord>> um;
```````````````````````````````````````````````````````````````
int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			um[nums[i][j]].push_back({ i, j });
		}
	}

	int target;
	cin >> target;
	int size = um[target].size();

	for (int i = 0; i < size; i++)
	{
		Coord now = um[target][i];
		cout << '(' << now.y << ',' << now.x << ')' << '\n';
	}

	return 0;
}