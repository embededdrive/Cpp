#include <iostream>
#include <unordered_map>

using namespace std;



int main()
{
	int arr[] = { 1, 200000000, 300000000, 1, 5 };

	unordered_map<int, int> um;

	for (int i = 0; i < 5; i++)
	{
		// 만약 이미 MAP에 키가 등록되어있다면
		// 해당 키 값에 연결된 value + 1
		// find(값) -> 없으면 um.end();

		if (um.find(arr[i]) != um.end())
		{
			um[arr[i]]++;
		}
		else {
			um.insert({ arr[i], 1 });
		}
	}

	// 등록한적 없는 Key로 um에 접근하는 순간 해당 key를 생성한다.
	// 다만 insert방식으로 key를 생성하는 것을 권한다.
	cout << um[3];

	// traversal / iteration
	// 시간복잡도가 보기와는 달리 오래걸린다 -> 시간초과
	// 이렇게 사용하지 않는 것을 권장 (디버그용)

	// Key가 구조체인 경우 -> B형

	for (auto it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << " " << it->second << '\n';
	}

	return 0;
}