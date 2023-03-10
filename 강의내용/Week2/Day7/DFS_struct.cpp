#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int n;
    int price;
};

//자동 추가 단축키 alt + Enter
vector<vector<Node>> alist(4);
int used[4];

void run(int now, int sum)
{
    if (now == 3)
    {
        cout << sum << endl;
        return;
    }

    for (int i = 0; i < alist[now].size(); i++)
    {
        Node next = alist[now][i];
        if (used[next.n]) continue;
        used[next.n] = 1;
        run(next.n, sum + next.price);
        used[next.n] = 0;
    }
}

int main() {
    alist[0] = { {1, 5}, {2, 7}, {3, 10} };
    alist[1] = { {2, 2}, {3, 1} };
    alist[2] = { {3, 1}, {0, 90 } };

    used[0] = 1;
    run(0, 0);

    return 0;
}