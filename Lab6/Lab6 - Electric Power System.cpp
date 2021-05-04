#include <bits/stdc++.h>
#include <cstring>
#include <climits>
// add two virtual nodes: s, t
#define s 0
#define t (V + 1)
using namespace std;

int V, E, P, M;
int graph[102][102], residual[102][102];

bool bfs(int src, int dest, int *parent)
{
    bool *visited = new bool[V + 2];
    memset(visited, false, sizeof(bool) * (V + 2));
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1; // root

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V + 2; v++)
        {
            if (!visited[v] && residual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[dest];
}

int ford_fulkerson(int src, int dest)
{
    for (int i = 0; i < V + 2; i++)
        for (int j = 0; j < V + 2; j++)
            residual[i][j] = graph[i][j];

    int *parent = new int[V + 2]; // store bfs result, traverse from parent[t]
    int ans = 0;

    while (bfs(src, dest, parent)) // while there is a path from s to t
    {
        int path = INT_MAX;
        int u, v;
        for (v = dest; v != src; v = u)
        {
            u = parent[v];
            path = min(path, residual[u][v]); // path flow is min weight on path
        }

        for (v = dest; v != src; v = u)
        {
            u = parent[v];
            residual[u][v] -= path;
            residual[v][u] += path;
        }
        ans += path;
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
        cin >> V >> E >> P >> M;
        for (int i = 0; i < V + 2; i++)
            for (int j = 0; j < V + 2; j++)
                graph[i][j] = 0;
        bool is_power[V + 2] = {false}, is_machine[V + 2] = {false};
        int tmp, src, dest;
        while (P--)
        {
            cin >> tmp;
            is_power[tmp] = true;
        }
        while (M--)
        {
            cin >> tmp;
            is_machine[tmp] = true;
        }
        for (int i = 0; i < E; i++)
        {
            cin >> src >> dest >> tmp;
            graph[src][dest] = tmp;

            if (is_power[src])
                graph[s][src] = INT_MAX;
            if (is_power[dest])
                graph[s][dest] = INT_MAX;

            if (is_machine[src])
                graph[src][t] = INT_MAX;
            if (is_machine[dest])
                graph[dest][t] = INT_MAX;
        }
        cout << ford_fulkerson(s, t) << "\n";
    }
}