#include <iostream>
#include <queue>

using namespace std;

int main()
{
	string str;

	cin >> str;

	priority_queue<char, vector<char>, less<char>> pq;
	
	/*
	// class를 함수처럼 사용하는 것
	// class의 변수를 함수로 넘겨 줄 수 있다

	less<char> a = less<char>();
	a(1, 3);
	less<char>()(1, 3);
	*/

	for (int i = 0; i < str.size(); i++)
	{
		pq.push(str[i]);
	}

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}

	return 0;
}