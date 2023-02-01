#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;

int main()
{
	arr.push_back({});
	arr.push_back({});
	arr.push_back({});

	arr[0] = { 1, 5, 4 };
	arr[1] = { 2, 2, 6 };
	arr[2] = { 9, 9, 1 };

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