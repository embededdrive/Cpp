#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(5);

void run(int now)
{
	cout << now;

	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		run(next);
	}
}

int main()
{
	arr[0] = { 3 };
	arr[1] = { 2, 0 };
	arr[2] = {};
	arr[3] = { 4, 2 };
	arr[4] = { 2 };

	run(0);

	return 0;
}