#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<vector<bool>> zero_weight;
vector<pair<int, int>> coor;

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

struct my_compare
{
    bool operator()(edge a, edge b)
    {
        return a.w < b.w;
    }
};

class subset
{
public:
    int parent, rank;
};

class graph
{
public:
    int v;
    vector<edge> edges;
    vector<subset> sets;

    graph(int V)
    {
        v = V;
    }

    void add_edge(int s, int d)
    {
        if (zero_weight[s][d])
            edges.push_back(edge(s, d, 0));
        else
        {
            int weight = (coor[s].first - coor[d].first) * (coor[s].first - coor[d].first);
            weight += (coor[s].second - coor[d].second) * (coor[s].second - coor[d].second);
            edges.push_back(edge(s, d, weight));
        }
    }

    int find(int a)
    {
        if (sets[a].parent != a)
            sets[a].parent = find(sets[a].parent);
        return sets[a].parent;
    }

    void merge(int a, int b)
    {
        sets[a].parent = b;
    }

    void Kruska()
    {
        vector<edge> ans;
        subset tmp;
        sort(edges.begin(), edges.end(), my_compare());
        for (int i = 0; i <= v; i++)
        {
            tmp.parent = i;
            tmp.rank = 0;
            sets.push_back(tmp);
        }
        int idx = 0;
        while (ans.size() < v - 1 && idx < edges.size())
        {
            edge now = edges[idx++];
            int a = find(now.s);
            int b = find(now.d);
            if (a != b)
            {
                if (!zero_weight[now.s][now.d])
                    ans.push_back(now);
                merge(a, b);
            }
        }

        cout << ans.size() << endl;
        for (edge e : ans)
        {
            cout << e.s << ' ' << e.d << endl;
        }
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
        int v;
        cin >> v;
        zero_weight = vector<vector<bool>>(v + 1, vector<bool>(v + 1, false));
        coor.clear();
        pair<int, int> tmp;
        coor.push_back(make_pair(-1, -1)); // idx starts from 1
        for (int i = 0; i < v; i++)
        {
            cin >> tmp.first >> tmp.second;
            coor.push_back(tmp);
        }
        int e;
        cin >> e;
        int x, y;
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            zero_weight[x][y] = zero_weight[y][x] = true;
        }
        graph g(v + 1);

        for (int s = 1; s <= v; s++)
            for (int d = s + 1; d <= v; d++)
                g.add_edge(s, d);

        g.Kruska();
    }
}