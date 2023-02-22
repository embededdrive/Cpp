#include <iostream>
#include <algorithm>

using namespace std;

/*

	QUIZ
  정렬 : 짝수 우선, 홀수 나중, 짝수는 내림차순, 홀수는 오름차순
  1 3 4 5 2
  4 2 1 3 5 

*/

bool cmp(int left, int right) {
	if (left % 2 == 0 && right % 2 == 1)
		return true;
	if (left % 2 == 1 && right % 2 == 0)
		return false;
	if (left % 2 == 0 && left > right)
		return true;
	if (left % 2 == 1 && left < right)
		return false;
	return false;
}

int main()
{
	int arr[] = { 1, 3, 4, 5, 2 };

	sort(arr, arr + 5, cmp);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}