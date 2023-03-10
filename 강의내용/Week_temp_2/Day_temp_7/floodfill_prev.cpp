#include <iostream>
#include <queue>

using namespace std;

int arr[3][3];
struct Node {
    int y, x;
};
queue<Node> q;
int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, 1, -1 };

int main()
{
    arr[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        //다음 갈수있는곳을 큐에 등록
        for (int t = 0; t < 4; t++)
        {
            int nY = now.y + directY[t];
            int nX = now.x + directX[t];
            if (nY < 0 || nX < 0 || nY >= 4 || nX >= 4) continue;
            if (arr[nY][nX] != 0) continue;

            arr[nY][nX] = arr[now.y][now.x] + 1;
            q.push({ nY, nX });
        }
    }

    return 0;
}