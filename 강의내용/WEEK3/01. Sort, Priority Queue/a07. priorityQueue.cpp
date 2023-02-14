#include <iostream>
#include <queue>

using namespace std;


int main()
{
	string str;

	cin >> str;

	priority_queue<char, vector<char>, less<char>> pq;
	// 기본값
	// MAX heap : less
	// MIN heap 으로 변경하려면 : greater

	// priority queue 에서 index로 접근하는 것은 권장하지 않는 방식
	
	for (int i = 0; i < str.size(); i++)
	{
		pq.push(str[i]);
	}

	/*
	for (int i = 0; i < pq.size(); i++)
	{
		cout << pq.top();
		pq.pop();
	}
	*/	// size 가 계속 변해서 끝까지 출력되지 않는다

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}

	return 0;
}