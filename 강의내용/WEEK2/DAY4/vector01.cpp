#include <iostream>
#include <vector>

using namespace std;

// vector<자료형> 변수이름
vector<int> v(5);	// 변수 초기화
					// v(parameter = 칸수[capacity] 0 으로 초기화가 된다)

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 5; i++)
	{
		cout << v[i] << ' ';
	}

	return 0;
}