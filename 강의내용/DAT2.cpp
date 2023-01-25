#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char buf[10] = "ABAACA";
	int dat[100] = { 0 };

	int n = strlen(buf);
	for (int i = 0; i < n; i++)
	{
		char ch = buf[i];
		dat[ch]++;			//값을 index로 사용하는 것
	}

	int max = 0;
	int maxIndex = 0;
	for (int i = 0; i < 100; i++)
	{
		if (dat[i] > max) {
			max = dat[i];
			maxIndex = i;
		}
	}

	cout << (char)maxIndex;

	return 0;
}