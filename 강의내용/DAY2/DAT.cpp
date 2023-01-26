#include <iostream>

using namespace std;

void bbq(int num)
{
	if (num == 2)
	{
		cout << num;
		return;
	}

	/*
	
	하향	/	방향에서만 실행
	
	*/

	bbq(num + 1);

	/*
	
	/＼	방향에서만 실행

	*/
	cout << num;

	bbq(num + 1);

	/*
	
	상향 ＼	방향에서만 실행

	*/

	int d = 1;
}

int main()
{
	bbq(0);

	return 0;
}