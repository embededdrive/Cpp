﻿#include<iostream>
#include<queue>
using namespace std;

int parent[10];

int Find(int now)
{
    if (now == parent[now]) {
        return now;
    }
    int ret = Find(parent[now]);
    parent[now] = ret;
    return ret;
}

void Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);

    if (pa == pb) return;
    parent[pb] = pa;
}


int main()
{
    parent[1] = 7;
    parent[2] = 7;
    parent[3] = 2;
    parent[4] = 5;
    parent[5] = 2;
    parent[7] = 7;

    cout << Find(7) << "\n";
    cout << Find(3) << "\n";
    cout << Find(2) << "\n";
    cout << Find(5) << "\n";
    return 0;
}