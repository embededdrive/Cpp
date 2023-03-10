#include <iostream>
#include <queue>

/*

__###
___#_
#_##_
__#__
#____
0 0
1 4
1 2

*/

using namespace std;

int y;
int x;
int by;
int bx;
int wy;
int wx;
int dist;

string map[5];

struct Node {
    int y;  // y좌표
    int x;  // x좌표
};

void bfs(int y, int x, int dy, int dx) {
    // # 1. queue 준비
    queue<Node> q;
    q.push({y, x});     // 배열처럼 연결된 구조로 저장 -> 순서에 맞게 저장

    // # 2. visited 준비
    int visited[5][5] = { 0 };
    visited[y][x] = 1;  // 시작 노드 방문 기록

    // # 3. 방향 배열
    int ydir[] = {-1, 1, 0, 0};
    int xdir[] = {0, 0, -1, 1};
    

    /*
    첫 좌표 0이 아님
    */

    // # 4. BFS 동작 (flood fill)
    while (!q.empty()) {
        // queue (대기열)의 맨 앞에 있는 노드를 추출
        Node now = q.front();
        q.pop();

        // now로 부터 갈 수있는 노드들을 확인하고, 그리고 queue 에 삽입
        // 갈 수 있는 방향 -> 문제에서 주어진다 -> 상하좌우로 퍼진다
        for (int i = 0; i < 4; i++)
        {
            // 다음 갈 수 있는 좌표를 일단 본다.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue;   // 여기는 못 간다

            // (ny, nx) 이미 방문했거나, 방문이 예약된 상태라면
            if (visited[ny][nx] != 0)
                continue;

            // 내가 지금 갈려고 하는 곳이 벽이라면
            if (map[ny][nx] == '#')
                continue;

            // --- 내가 (ny, nx)를 갈 수 있다! 라는게 확정
            // 방문기록 (예약)
            // 다음 좌표까지의 경로 = 현재 위치까지의 경로에서 +1번 더 퍼져나간 경로
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }

    // -- while이 끝나면 -- visited가 다 채워진 상태
    /*
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << visited[i][j] - 1 << ' ';
        }
        cout << '\n';
    }
    */
    dist += visited[dy][dx];
}

int main()
{
    int cnt = 0;

    for (int i = 0; i < 5; i++)
        cin >> map[i];

    cin >> y >> x;
    // bfs (시작 노드)
    // bfs (시작 좌표) -> bfs (y, x)

    cin >> by >> bx;
    cin >> wy >> wx;

    bfs(y, x, wy, wx);
    bfs(wy, wx, by, bx);

    cout << dist;

    return 0;
}