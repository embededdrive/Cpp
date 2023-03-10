#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr = { 5, 3, 1, 6, 8, 9, 2, 4, 10, 7 };

	sort(arr.begin(), arr.end());
	// [ begin , end )
	// 대괄호 : 포함, 소괄호 : 포함 X

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}


	return 0;
}