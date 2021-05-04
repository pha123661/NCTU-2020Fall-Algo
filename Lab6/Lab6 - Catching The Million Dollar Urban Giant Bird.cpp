#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

// Codeforces 30C
// 有點像背包問題

class bird
{
public:
    int x, y, t, rwd;
};

bool my_compare(bird a, bird b)
{
    return a.t < b.t;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        vector<bird> birds;
        vector<int> dp(1001, 0);
        bird tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp.x >> tmp.y >> tmp.t >> tmp.rwd;
            birds.push_back(tmp);
        }
        sort(birds.begin(), birds.end(), my_compare);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = birds[i].rwd; // may start from scratch
            for (int j = 0; j < i; j++)
            {
                long long int t1, t2, tmp1, tmp2;
                t1 = (birds[i].t - birds[j].t) * (birds[i].t - birds[j].t);
                tmp1 = (birds[i].x - birds[j].x) * (birds[i].x - birds[j].x);
                tmp2 = (birds[i].y - birds[j].y) * (birds[i].y - birds[j].y);
                t2 = tmp1 + tmp2;
                if (t1 >= t2)
                {
                    dp[i] = max(dp[i], dp[j] + birds[i].rwd);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}