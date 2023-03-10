#include <iostream>

using namespace std;

int x = 0;

void BBQ() {
	if (x == 2)
	{
		return;
	}
	cout << x << "\n";
	x++;
	BBQ();

	int d = 1;
}

int main()
{
	BBQ();

	return 0;
}