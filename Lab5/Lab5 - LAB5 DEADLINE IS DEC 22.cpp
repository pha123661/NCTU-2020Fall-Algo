#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class djset
{
public:
    djset(int n)
    {
        num = n;
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
        }
    }
    int find(int a)
    {
        a = min(a, num);
        if (parent[a] == a)
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    void merge(int p, int child)
    {
        parent[child] = p;
    }
    int num;
    vector<int> parent;
};

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
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
        int n;
        pair<int, int> tmp;
        vector<pair<int, int>> jobs; // deadline, reward
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp.first >> tmp.second;
            jobs.push_back(tmp);
        }
        sort(jobs.begin(), jobs.end(), compare());
        int avai;
        unsigned long long ans = 0;
        djset dj(n);
        for (auto j : jobs)
        {
            avai = dj.find(j.first);
            if (avai)
            {
                ans += j.second;
                dj.merge(dj.find(avai - 1), avai);
            }
        }
        cout << ans << "\n";
    }
}