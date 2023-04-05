#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
vector<int> nodes[N];
bool vis[N];
int par[N], dis[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : nodes[x])
        {
            if (!vis[y])
            {
                q.push(y);
                par[y] = x;
                dis[y] = dis[x] + 1;
                vis[y] = 1;
            }
        }
    }
}
void pathprint(int x)
{
    vector<int> path;
    while (par[x] != x)
    {
        path.push_back(x);
        x = par[x];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    int i, n, e, u, v;
    cin >> n >> e;
    for (i = 0; i < e; i++)
    {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bfs(0);
    pathprint(5);
    cout << dis[8] << endl;
    // input
    // 11 12
    // 0 2
    // 0 4
    // 2 1
    // 2 3
    // 2 9
    // 4 7
    // 4 10
    // 9 7
    // 7 10
    // 3 5
    // 7 6
    // 10 8
}
