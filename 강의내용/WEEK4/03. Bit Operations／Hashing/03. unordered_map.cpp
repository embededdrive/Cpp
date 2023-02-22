#include <iostream>
#include <unordered_map>

using namespace std;



int main()
{
	int arr[] = { 1, 200000000, 300000000, 4, 5 };

	// MAP 생성
	// unordered_map<key type, value type>

	unordered_map<int, int> um;

	for (int i = 0; i < 5; i++)
	{
		um.insert({ arr[i], 1 });
	}

	cout << um[200000000];

	return 0;
}