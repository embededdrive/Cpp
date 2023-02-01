#include <iostream>
using namespace std;

int sum = 0;
int visited[4] = { 0, };
int map[4][4] =
{
    0,7,20,8,
    0,0,5,0,
    15,0,0,0,
    0,0,6,0
};  // 인접행렬 하드코딩 map[노드개수][노드개수]

void dfs(int now, int sum)
{

    if (now == 2)   // 2번 노드(부산)에 도착했다면
    {......................................................
        cout << sum << endl;    //총합 출력
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (map[now][i] == 0) continue;
        if (visited[i] == 1) continue;

        visited[i] = 1;
        dfs(i, sum + map[now][i]);
        visited[i] = 0;
    }

}

int main()
{
    visited[0] = 1; // 시작 노드는 방문배열에 1을 체크
    dfs(0, sum);         // 시작 노드번호, sum 값

    return 0;
}
