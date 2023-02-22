#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

string ccc[100];

map<int, string> kkk;
unordered_map<int, string> ggg;

int main()
{
	// 배열의 경우 (DAT의 한계)
	// 한계
	// 1. 인덱스에 음수 사용불가
	// 2. 인덱스에 아주 큰 수 사용 불가
	// 3. 인덱스에 문자열 사용 불가
	//
	ccc[100] = "KDKDKD";



	kkk[100] = "HUHUHU";
	ggg[100] = "HAHAHA";

	cout << kkk[100] << '\n';
	cout << ggg[100] << '\n';

	return 0;
}