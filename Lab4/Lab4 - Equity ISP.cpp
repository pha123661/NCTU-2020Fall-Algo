#include <bits/stdc++.h>
#include <climits>
#include <cstring>
using namespace std;

class Edge
{
public:
    int s, d, w;
    Edge(int a, int b, int c)
    {
        s = a;
        d = b;
        w = c;
    }
};

class subset // single parent has multiple child
{
public:
    int parent;
    int rank;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

class graph
{
public:
    int V_num, E_num;
    vector<Edge> edge, ans;
    subset sets[101];
    graph(int v)
    {
        V_num = v + 1;
        E_num = 0;
    }

    inline int find_root(int i)
    {
        if (sets[i].parent != i)
            sets[i].parent = find_root(sets[i].parent);
        return sets[i].parent;
    }

    inline void U(int a, int b) // (set A) U (set B) operation
    {
        int root_a = find_root(a);
        int root_b = find_root(b);

        if (sets[root_a].rank < sets[root_b].rank)
            sets[root_a].parent = root_b;
        else if (sets[root_a].rank > sets[root_b].rank)
            sets[root_b].parent = root_a;
        else
        {
            sets[root_a].parent = root_b;
            sets[root_b].rank += 1;
        }
    }

    inline void add_edge(int s, int d, int w)
    {
        edge.push_back(Edge(s, d, w));
        E_num++;
    }

    int Kruska(int idx_lower_bound_edge)
    {
        ans.clear();

        for (int i = 0; i < V_num; i++) // init
        {
            sets[i].parent = i;
            sets[i].rank = 0;
        }

        int e = 0;                      // numbers of edges added to MST
        int idx = idx_lower_bound_edge; // which edge we are
        while (e < V_num - 1 && idx < E_num)
        {
            Edge now = edge[idx++];
            int a = find_root(now.s);
            int b = find_root(now.d);

            if (a != b) // this edge doesn't make a cycle -> add it
            {
                ans.push_back(now);
                e++;
                U(a, b);
            }
        }

        // output
        if (ans.size() == (V_num - 2)) // V_num = v+1
        {
            return (ans.back().w - ans.front().w);
        }
        else
        {
            return INT_MAX;
        }
    }
};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int V, E, ans;
        int tmp1, tmp2, tmp3;
        cin >> V >> E;
        graph g(V);
        for (int i = 0; i < E; i++)
        {
            cin >> tmp1 >> tmp2 >> tmp3;
            g.add_edge(tmp1 - 1, tmp2 - 1, tmp3);
        }
        sort(g.edge.begin(), g.edge.end(), compare);
        int min = INT_MAX;
        for (int i = 0; i < E; i++)
        {
            ans = g.Kruska(i);
            if (i == 0 && ans == INT_MAX)
                break;
            if (ans < min)
                min = ans;
        }
        if (min == INT_MAX)
            cout << "-1\n";
        else
            cout << min << endl;
    }
}