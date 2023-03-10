#include <iostream>

using namespace std;

int main()
{
	/*
	
	구간의 합이 target이 되는
	경우의 수를 세는 문제
	
	*/

	int arr[] = { 1, 2, 3, 1, 2, 3, 5, 6, 7, 8 };
	// target
	int target = 1;

	// two pointer
	int left = 0;	// slow pointer
	int right = 0;	// fast pointer

	int sum = 0;
	int cnt = 0;

	while (right <= 10) {
		if (sum == target) {
			cnt++;
			sum -= arr[left];
			left++;
		}
		else if (sum < target)
		{
			// sum에 fast pointer (right)가 가리키는 값을 더하고
			sum += arr[right];
			// right를 한칸 이동
			right++;
		}
		else if (sum > target)
		{
			// sum에서 slow pointer (left)가 가리키는 값을 빼고
			sum -= arr[left];
			// left를 한칸 이동
			left++;
		}
	}

	cout << cnt;

	return 0;
}