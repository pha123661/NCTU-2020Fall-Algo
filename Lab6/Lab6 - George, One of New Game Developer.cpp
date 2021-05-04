#include <bits/stdc++.h>
#include <cstring>
using namespace std;
// uva 10559 https://onlinejudge.org/external/105/10559.pdf
// uva 11523 https://onlinejudge.org/external/115/11523.pdf

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        string str;
        cin >> n >> str;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = i; k < j; k++)
                {
                    if (str[i] == str[j])
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }
}