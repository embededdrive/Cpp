#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, vector<int>> um;
// unordered_multimamp과 동일한 역할

int main()
{
	um["ABC"].push_back(1);

	return 0;
}