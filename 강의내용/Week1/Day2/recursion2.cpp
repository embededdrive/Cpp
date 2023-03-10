#include <iostream>

using namespace std;

int arr[5] = { 3, 7, 5, 4, 2 };

void run(int num)
{
	if (num == 5)
	{
		cout << '\n';
		return;
	}

	cout << arr[num];
	run(num + 1);
	cout << arr[num];
}

int main()
{
	run(0);

	return 0;
}