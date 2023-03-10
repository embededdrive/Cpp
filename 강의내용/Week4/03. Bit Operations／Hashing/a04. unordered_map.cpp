#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
	int age;
	string name;
	string iq;
};

int main()
{
	unordered_map<string, Node> um;

	um["56"] = { 15, "SO", "56" };
	um["SO"] = { 15, "SO", "56" };

	um["60"] = { 66, "GO", "60" };
	um["GO"] = { 66, "GO", "60" };

	string str;
	cin >> str;

	if (um.count(str))
	{
		if (um[str].name != str) cout << um[str].name << '\n';
		if (um[str].iq != str) cout << um[str].iq << '\n';
		cout << um[str].age << '\n';
	}

	return 0;
}