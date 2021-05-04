#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

// uva 515 https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=456

class edge
{
public:
    int s, d, w;
    edge(int S, int D, int W)
    {
        s = S;
        d = D;
        w = W;
    }
};

class graph
{
public:
    int v;
    vector<edge> edges;

    graph(int V)
    {
        v = V;
    }

    void add_edge(int s, int d, int w)
    {
        edges.push_back(edge(s, d, w));
    }

    bool BF()
    {
        int src = 0;
        int *dist = new int[v];
        memset(dist, INT_MAX, sizeof(int) * v);
        dist[src] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (auto eg : edges)
            {
                if (dist[eg.s] == INT_MAX)
                    continue;
                dist[eg.d] = min(dist[eg.d], dist[eg.s] + eg.w);
            }
        }

        for (auto eg : edges)
        {
            if (dist[eg.s] != INT_MAX && dist[eg.d] > dist[eg.s] + eg.w)
                return true;
        }
        return false;
    }
};

int main()
{
    int n, m;
    int i, j, w;
    char op;
    string str;
    while (cin >> n >> str)
    {
        if (!isdigit(str[0]))
            break;
        m = stoi(str);
        graph g(n + 1);
        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> op >> w;
            if (op == '<')
                g.add_edge(i - 1, i + j, w - 1);
            else
                g.add_edge(i + j, i - 1, -w - 1);
        }
        if (g.BF())
            cout << "There is no bus in Gensokyo.\n";
        else
            cout << "All aboard the hype bus choo choo.\n";
    }
}