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

	int n;

	cin >> n;

	for (int i = 0; i < arr[n].size(); i++)
	{
		cout << arr[n][i];
	}

	return 0;
}