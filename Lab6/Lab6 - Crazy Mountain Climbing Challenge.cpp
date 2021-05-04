#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

vector<int> cache;

int bsearch(int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (cache[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, len;
        cin >> n;
        vector<int> dp1(n + 1, 1), dp2(n + 1, 1), data(n + 1, 0);
        cache = vector<int>(n + 1, -1);
        for (int i = 1; i <= n; i++)
            cin >> data[i];

        // LIS
        dp1[1] = 1;
        cache[1] = data[1];
        len = 1;
        for (int i = 2; i <= n; i++)
        {
            dp1[i] = bsearch(1, len, data[i]);
            len = max(len, dp1[i]);
            cache[dp1[i]] = data[i];
        }

        // LDS
        dp2[n] = 1;
        cache[1] = data[n];
        len = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            dp2[i] = bsearch(1, len, data[i]);
            len = max(len, dp2[i]);
            cache[dp2[i]] = data[i];
        }

        int max_n = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp1[i] >= 2 && dp2[i] >= 2)
                max_n = max(max_n, dp1[i] + dp2[i] - 1);
        }
        cout << n - max_n << endl;
    }
}