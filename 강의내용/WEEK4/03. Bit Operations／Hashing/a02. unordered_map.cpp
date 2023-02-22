#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

string arr[] = { "HI", "HI", "GGG", "HI", "GGG" };

unordered_map<string, int> um;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		um[arr[i]] += 1;
	}

	string str;

	cin >> str;

	// Key 값이 있는지 물어보는 경우 (유의사항)

	/*
	// 등록되지 않은 key값을 읽으면 0으로 자동 추가된다
	if (um[str] == 0)
		cout << "없음";
	*/

	
	// 카운트로 접근하면 된다!
	if (um.count(str) == 0)
		cout << "없음";
	
	return 0;
}