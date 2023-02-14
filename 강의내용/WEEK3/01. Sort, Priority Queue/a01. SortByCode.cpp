#include <iostream>

using namespace std;

int main()
{
	int arr[10] = { 5, 3, 1, 6, 8, 9, 2, 4, 10, 7};

	int prev = 0;
	for (int i = 0; i < 10; i++)
	{
		int minValue = 100;
		for (int x = 0; x < 10; x++)
		{
			if (prev < arr[x] && arr[x] < minValue) {
				minValue = arr[x];
			}
		}
		prev = minValue;
		cout << minValue << ' ';
	}

	return 0;
}