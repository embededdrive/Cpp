#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string left, string right) {
	if (left.length() > right.length())
		return false;
	if (left.length() < right.length())
		return true;
	if (left > right)
		return false;
	if (left < right)
		return true;
	return false;
}

int main()
{
	int n;
	string names[20];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> names[i];
	}

	sort(names, names + n, cmp);

	for (int i = 0; i < n; i++)
	{
		cout << names[i] << '\n';
	}

	return 0;
}