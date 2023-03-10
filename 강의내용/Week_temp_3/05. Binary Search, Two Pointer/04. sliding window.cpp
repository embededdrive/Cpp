#include <iostream>

using namespace std;

int main()
{
	/*

	크기 3인 구간의 합
	최소값 찾는 문제

	*/

	int arr[] = { 1, 1, 8, 1, 2, 3, 5, 6, 7, 8 };
	int N = 3;

	// 1. 초기 포인터 세팅
	int left = 0;
	int right = N - 1;		// index가 0부터 시작하는 경우 : 구간크기 - 1

	// 2. 초기 공통구간 세팅
	int sum = 0;
	for (int i = left; i < right; i++)
		sum += arr[i];

	// 3. sliding window
	int ans = 21e8;
	// right 포인터가 범위를 벗어나지 않을 때까지
	while (right < 10)
	{
		// 구간 완성
		sum += arr[right];

		// 수행
		if (sum < ans)
			ans = sum;

		// 다음 공통구간 만들기
		sum -= arr[left];

		// left와 right 포인터 이동
		left++;
		right++;
	}

	cout << ans;

	return 0;
}