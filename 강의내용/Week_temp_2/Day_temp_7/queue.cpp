#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // queue 사용법

    queue<int> q;   // queue 생성

    // # 1. 삽입
    q.push(1);  // [ 1     ]
    q.push(2);  // [ 1 2   ]
    q.push(3);  // [ 1 2 3 ]
    
    // # 2. peek -> queue의 맨 앞 값을 확인
    cout << q.front();

    // # 3. size() -> queue에 몇개의 요소가 있는가?
    cout << q.size();

    // # 4. empty() -> queue가 비어있으면 true(1), 아니면 false(0)
    cout << q.empty();

    // # 5. pop() -> queue의 맨 앞의 요소를 삭제
    cout << q.front();


    return 0;
}