#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int *origin;

class graph
{
public:
    int vertics_num;
    int *visited;
    list<int> *adjacency_list;
    graph(int n);
    void add_edge(int src, int dest);
    void mark(int v);
    void solver();
};

graph ::graph(int n)
{
    this->vertics_num = n;
    this->visited = new int[n];
    memset(visited, 0, sizeof(int) * n);
    this->adjacency_list = new list<int>[n];
}

void graph ::add_edge(int src, int dest)
{
    adjacency_list[src].push_back(dest);
}

void graph ::mark(int v)
{
    for (auto it : adjacency_list[v])
    {
        if (visited[it])
            continue;
        visited[it] = 1;
        mark(it);
    }
}

void graph ::solver()
{
    int ans = 0;
    for (int i = 0; i < vertics_num; i++)
    {
        if (origin[i])
        {
            visited[i] = 1;
            mark(i);
            ans++;
        }
    }
    if (ans == 0)
    {
        cout << 1 << endl;
        return;
    }
    // points with any origin was marked
    // deal with cycle
    for (int i = 0; i < vertics_num; i++)
    {
        if (!visited[i])
        {
            ans++;
            mark(i);
        }
    }
    cout << ans << endl;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int E, num;
        cin >> E >> num;
        graph g(E);
        origin = new int[E];
        memset(origin, 1, sizeof(int) * E);
        for (int i = 0; i < num; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            g.add_edge(v1 - 1, v2 - 1);
            origin[v2 - 1] = 0;
        }
        g.solver();
    }
}