#include <iostream>
#include <queue>

using namespace std;

/*

1. 짝수 우선
2. 작은값 우선
3. 알파벳 순서

*/

struct Node {
	int num;
	char ch;
};

// function operator
struct cmp
{
	bool operator()(Node& left, Node& right) {
		if (left.num % 2 == 1 && right.num % 2 == 0)
			return true;
		if (left.num % 2 == 0 && right.num % 2 == 1)
			return false;
		if (left.num > right.num)
			return true;
		if (left.num < right.num)
			return false;
		if (left.ch > right.ch)
			return true;
		if (left.ch < right.ch)
			return false;
		return false;
	}
};