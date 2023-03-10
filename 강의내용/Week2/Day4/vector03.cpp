#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// vector<int> v; capacity 가 얼마나 들어갈지 모를때
	// vector<int> v(5); // 5의 capacity를 가지는 벡터에서 안의 원소는 0으로 초기화
	// vector<int> v(5, 2);	// 5의 capacity를 가지는 벡터에서 안의 원소는 2으로 초기화

	vector<int> v;

	v.push_back(3);
	v.push_back(4);
	v.push_back(1);

	cout << v.front();		// 첫번째 원소를 참조한다.

	cout << endl;

	cout << v.back();		// 마지막 원소를 참조한다.

	return 0;
}