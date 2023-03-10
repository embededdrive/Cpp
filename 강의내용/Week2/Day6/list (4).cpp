#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(5);

int main()
{
	arr[0] = { 3 };
	arr[1] = { 2, 0 };
	arr[2] = {};
	arr[3] = { 4, 2 };
	arr[4] = { 2 };

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}