#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

string nums[4] = { "63", "11", "55", "30" };
string names[4] = { "Jodan", "Park", "Jony", "Tiger" };

unordered_map<string, string> umName, umNum;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		umName[nums[i]] = names[i];
		umNum[names[i]] = nums[i];
	}

	string input;

	cin >> input;

	if (umName.count(input) > 0) cout << umName[input];
	if (umNum.count(input) > 0) cout << umNum[input];

	return 0;
}