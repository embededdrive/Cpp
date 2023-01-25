#include <iostream>

using namespace std;

int main()
{
	char temp[100];
	cin >> temp;

	int DAT[256] = { 0 }; // 기본적인 문자 : 128가지, char라는 data가 표현 가능한 종류 : 256 가지

	for (int i = 0; i < temp[i]; i++)
	{
		char now = temp[i];
		DAT[now]++;	//now라는 문자가 1개 추가
	}

	return 0;
}