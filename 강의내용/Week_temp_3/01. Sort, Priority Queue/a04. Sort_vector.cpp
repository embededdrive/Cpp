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

	for (int value : arr)	// arr / vec 의 값을 value에 하나씩 복사
	{
		cout << value << ' ';
	}

	for (int& value : arr)	// arr / vec 의 값을 참조 (레퍼런스 형태)
	{
		cout << value << ' ';
	}

	for (const value : arr)	// 값을 수정 못하도록
	{
		cout << value << ' ';
	}

	return 0;
}