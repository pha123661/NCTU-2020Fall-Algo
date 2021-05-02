#include <bits/stdc++.h>
#include <climits>
using namespace std;

class graph
{
public:
    graph(int V)
    {
        v = V;
        adj = new vector<pair<int, int>>[v];
    }

    void add_edge(int s, int d, int w)
    {
        adj[s].push_back(make_pair(d, w));
        adj[d].push_back(make_pair(s, w));
    }

    int dj(int src, int dest)
    {
        vector<int> dist(v, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> flag(v, false);

        dist[src] = 0;
        pq.push(make_pair(dist[src], src));

        while (!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            if (flag[v])
                continue;
            flag[v] = true;
            for (auto pr : adj[v])
            {
                int u = pr.first;
                int weight = pr.second;
                if (!flag[u] && dist[u] > dist[v] + weight)
                {
                    dist[u] = dist[v] + weight;
                    pq.push(make_pair(dist[u], u));
                }
            }
        }
        return dist[dest];
    }
    int v;
    vector<pair<int, int>> *adj;
};

int main()
{
    cin.tie();
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int v, e, src, dest;
        int s, d, w;
        cin >> v >> e >> src >> dest;
        graph g(v);
        for (int i = 0; i < e; i++)
        {
            cin >> s >> d >> w;
            g.add_edge(s, d, w);
        }
        int ans = g.dj(src, dest);
        if (ans == INT_MAX)
            cout << "YOU DIED\n";
        else
            cout << ans << "\n";
    }
}