#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

6 9
1 2 2
1 4 1
1 5 4
2 3 3
2 4 3
2 6 7
3 4 5
3 6 8
4 5 9

*/

struct Edge {
    int from, to;
    int cost;
};

int nodeCnt, edgeCnt;
vector<Edge> v;
int parent[7];

bool cmp(Edge left, Edge right) {
    return left.cost < right.cost;
}

int find(int now) {
    if (now == parent[now]) return now;

    int ret = find(parent[now]);
    parent[now] = ret;
    return ret;
}

void uunion(int a, int b)
{
    int ra = find(a);
    int rb = find(b);

    if (ra == rb) return;

    parent[rb] = ra;
}

int kruskal()
{
    sort(v.begin(), v.end(), cmp);


    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // edge를 MST에 포함할지 말지 -> Union Find 로 작성하기
        if (find(v[i].from) == find(v[i].to))
            continue;
        
        sum += v[i].cost;
        uunion(v[i].to, v[i].from);
    }

    return sum;
}

int main()
{
    for (int i = 0; i < 7; i++)
        parent[i] = i;

    cin >> nodeCnt >> edgeCnt;

    for (int i = 0; i < edgeCnt; i++)
    {
        int a, b, cost;

        cin >> a >> b >> cost;

        v.push_back({a, b, cost});
    }

    cout << kruskal();

    return 0;
}