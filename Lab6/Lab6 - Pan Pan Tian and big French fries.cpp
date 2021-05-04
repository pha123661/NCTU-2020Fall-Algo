#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

int s, t, v;
int graph[203][203], residual[203][203];

bool bfs(int src, int *parent)
{
    bool *visited = new bool[v];
    memset(parent, false, sizeof(bool) * v);
    parent[src] = -1;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int n = 0; n < v; n++)
        {
            if (residual[u][n] > 0 && !visited[n])
            {
                q.push(n);
                parent[n] = u;
                visited[n] = true;
            }
        }
    }
    return visited[t];
}

int ff()
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            residual[i][j] = graph[i][j];

    int *parent = new int[v];
    memset(parent, 0, sizeof(int) * v);
    int ans = 0;
    while (bfs(s, parent))
    {
        int flow = INT_MAX;
        for (int u = t; u != s; u = parent[u])
        {
            flow = min(flow, residual[parent[u]][u]);
        }
        ans += flow;
        for (int u = t; u != s; u = parent[u])
        {
            residual[parent[u]][u] -= flow;
            residual[u][parent[u]] += flow;
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int v1, v2, e;
        int x, y;
        cin >> v1 >> v2 >> e;
        v = v1 + v2 + 2;
        s = v1 + v2;
        t = s + 1;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                graph[i][j] = 0;
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            y += v1;
            graph[x][y] = 1;
            graph[s][x] = 1;
            graph[y][t] = 1;
        }

        cout << ff() << "\n";
    }
}