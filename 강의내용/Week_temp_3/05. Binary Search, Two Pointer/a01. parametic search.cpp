#include <iostream>

using namespace std;

/*

순서대로 떨어지는 아이스크림을 다 받을 수 있는 크기가 동일한 3개의 컵의 최소 용량

*/

int ices[6] = { 120, 50, 70, 90, 10, 30 };

bool isOkay(int size) {
	int cup[3] = { size, size, size };

	for (int i = 0; i < 6; i++)
	{
		if (ices[i] <= cup[0])
		{
			cup[0] -= ices[i];
		}
		else if (ices[i] <= cup[1])
		{
			cup[1] -= ices[i];
		}
		else if (ices[i] <= cup[2])
		{
			cup[2] -= ices[i];
		}
		else {
			return false;
		}
	}
	return true;
}

int main()
{
	int left = 120;
	int right = 400;
	int ml;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (isOkay(mid))
		{
			ml = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ml;

	return 0;
}