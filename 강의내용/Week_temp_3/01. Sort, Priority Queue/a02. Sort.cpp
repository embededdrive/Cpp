#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[10] = { 5, 3, 1, 6, 8, 9, 2, 4, 10, 7};

	sort(arr, arr + 10);
	// 배열의 시작 주소, 배열의 끝 주소
	// [ begin , end )
	// 대괄호 : 포함, 소괄호 : 포함 X


	return 0;
}