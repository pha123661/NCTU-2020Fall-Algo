#include <bits/stdc++.h>
#include <climits>
#include <cstring>
using namespace std;

struct my_compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
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
        vector<pair<int, int>> jobs;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp.first >> tmp.second;
            jobs.push_back(tmp);
        }
        sort(jobs.begin(), jobs.end(), my_compare());
        int now = 0, ans = 0;
        for (auto j : jobs)
        {
            if (j.first >= now)
            {
                now = j.second;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}