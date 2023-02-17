#include <iostream>
#include <algorithm>

using namespace std;

int arr[] = { 3, 99, 21, 33, 4, 1, 5, 55, 7, 10 };

void bs(int target)
{
	// #1. 내가 어떤 범위를 탐색하는가?
	// --> 배열 내에만 존재하는 요소를 찾는다 : index
	// --> 특정 정수 내의 범위이다 : 시작 끝
	int left = 0;
	int right = size(arr) - 1;
	int flag = 0;

	while (left <= right) {
		// mid를 예측한다
		int mid = (left + right) / 2;
		if (arr[mid] == target) {
			flag = 1;
			break;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else if (target > arr[mid]) {
			left = mid + 1;
		}
	}

	cout << flag;
}

int main()
{
	int target;

	cin >> target;		// 찾고자 하는 숫자

	// binary search
	// target을 찾아가는 이진탐색
	sort(arr, arr + 10);
	bs(target);

	return 0;
}