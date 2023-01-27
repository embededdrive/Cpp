#include <iostream>
#include <cstring>

using namespace std;

char name[10] = "BTSGOOD";
int len;
char path[10];

void run(int lev)
{
	if (lev == 3)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < len; i++)
	{
		path[lev] = name[i];
		run(lev + 1);
		path[lev] = 0;
	}

}

int main()
{
	len = name.getlength();
	run(0);

	return 0;
}