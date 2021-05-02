#include <bits/stdc++.h>
#include <climits>
using namespace std;

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

    bool BF(int src)
    {
        vector<int> dist(v, INT_MAX);
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
    cin.tie();
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int v, e;
        int s, d, w;
        cin >> v >> e;
        graph g(v);
        for (int i = 0; i < e; i++)
        {
            cin >> s >> d >> w;
            g.add_edge(s, d, w);
        }
        if (g.BF(0))
            cout << "This is the choice of Steins;Gate\n";
        else
            cout << "El Psy Kongroo\n";
    }
}