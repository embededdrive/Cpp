#include <iostream>
#include <algorithm>

using namespace std;

/*



*/

int getMin(int price) {
	if (price < 0) return 21e8;
	if (price == 0) return 0;

	// 후보 1
	int a = getMin(price - 10) + 1;	// 90원 정답 + 10원 1개
	int b = getMin(price - 50) + 1;	// 50원 정답 + 50원 1개
	int c = getMin(price - 70) + 1;	// 30원 정답 + 70원 1개

	int result = min(min(a, b), c);
	return result;
}

int main() {
	
	int ret = getMin(100);
	cout << ret << " 개";

	return 0;
}