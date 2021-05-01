#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;
// single source longest destance in directed graph

typedef struct test
{
    int v, weight;
} adjnode;

class graph
{
private:
    int vertics_num;
    int *visited;
    int *connected_to_src;

public:
    list<adjnode> *adjacency_list;
    graph(int n);
    void add_edge(int src, adjnode dest);
    void topologicalsort(int v, bool visited[], stack<int> &stack);
    void solver(int src);
    void mark(int src);
};

graph ::graph(int n)
{
    this->vertics_num = n;
    this->visited = new int[n];
    memset(visited, 0, sizeof(int) * n);
    this->adjacency_list = new list<adjnode>[n];
    this->connected_to_src = new int[vertics_num];
    memset(this->connected_to_src, 0, sizeof(int) * vertics_num);
}

void graph ::add_edge(int src, adjnode dest)
{
    adjacency_list[src].push_back(dest);
}

void graph::topologicalsort(int v, bool visited[], stack<int> &stack)
{
    visited[v] = 1;
    for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end(); it++)
    {
        if (visited[it->v])
            continue;
        topologicalsort(it->v, visited, stack);
    }
    stack.push(v);
}

void graph ::mark(int src)
{
    connected_to_src[src] = 1;
    for (auto i : adjacency_list[src])
    {
        mark(i.v);
    }
}

void graph ::solver(int src)
{
    stack<int> toporoder;
    bool *visited = new bool[vertics_num];
    memset(visited, 0, sizeof(bool) * vertics_num);
    // topologicalsort
    for (int i = 0; i < vertics_num; i++)
    {
        if (visited[i])
            continue;
        topologicalsort(i, visited, toporoder);
    }

    int *dist = new int[vertics_num];
    memset(dist, INT_MIN, sizeof(int) * vertics_num);
    dist[src] = 0;
    mark(src);
    while (!toporoder.empty())
    {
        int v = toporoder.top();
        toporoder.pop();
        if (!connected_to_src[v])
            continue;
        for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end(); it++)
        {
            if (dist[it->v] < dist[v] + it->weight)
                dist[it->v] = dist[v] + it->weight;
        }
    }

    // find max
    int max = INT_MIN;
    for (int i = 0; i < vertics_num; i++)
    {
        if (dist[i] >= max)
            max = dist[i];
    }
    cout << max << endl;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, origin, from;
        adjnode tmp;
        cin >> n >> origin;
        graph g(n);
        for (int i = 0; i < n; i++)
        {
            tmp.v = i;
            cin >> from >> tmp.weight;
            if (from < 0)
                continue;
            g.add_edge(from, tmp);
        }
        g.solver(origin);
    }
}