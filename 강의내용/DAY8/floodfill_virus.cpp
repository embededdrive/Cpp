#include <iostream>
#include <queue>

using namespace std;

int sy, sx;

struct Node {
    int y;  // y좌표
    int x;  // x좌표
};

void bfs(int y, int x) {
    // # 1. queue 준비
    queue<Node> q;
    q.push({y, x});     // 배열처럼 연결된 구조로 저장 -> 순서에 맞게 저장

    // # 2. visited 준비
    int visited[5][5] = { 0 };
    visited[y][x] = 1;  // 시작 노드 방문 기록

    // # 3. 방향 배열
    int ydir[] = {-1, 1, 0, 0};
    int xdir[] = {0, 0, -1, 1};
    
    int day = 1;

    cout << "Day #" << day << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << visited[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';

    // # 4. BFS 동작 (flood fill)
    while (!q.empty()) {
        // 다음 날이 되었다!
        day++;

        //지금 queue에서 오늘 날짜에 감염될 node 만큼만을 추출해서 기록
        int cursize = q.size();
        for (int j = 0; j < cursize; j++)
        {
            Node now = q.front();
            q.pop();

            // now로 부터 갈 수있는 노드들을 확인하고, 그리고 queue 에 삽입
            // 갈 수 있는 방향 -> 문제에서 주어진다 -> 상하좌우로 퍼진다
            for (int i = 0; i < 4; i++)
            {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue;
            
            if (visited[ny][nx] == 1)
                continue;

            // --- 내가 (ny, nx)를 갈 수 있다! 라는게 확정
            // 방문기록 (예약)
            // 다음 좌표까지의 경로 = 현재 위치까지의 경로에서 +1번 더 퍼져나간 경로
            visited[ny][nx] = 1;
            q.push({ ny, nx });
            }
        }


        cout << "Day #" << day << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cout << visited[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> sy >> sx;
    bfs(sy, sx);

    return 0;
}