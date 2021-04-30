#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int ans = 0, n, m;
int **g;
bool **used;

void dfs(int x, int y, int d)
{
    //cout << "now at: " << x << " ," << y << " ," << d << endl;
    if (x == n - 1 && y == m - 1) // we made it!
    {
        ans++;
        return;
    }
    used[x][y] = 1;
    // blank = 0, line = 1, turn = 2
    if (d == 0) // possible to go horizontal
    {
        //cout << "d == 0\n";
        // try go left
        if (x - 1 < 0 || used[x - 1][y] || g[x - 1][y] == 0)
        {
        }
        else // left boundary
        {
            //cout << "can go left\n";
            if (g[x - 1][y] == 1) // left is a line
                dfs(x - 1, y, 0);
            else
                dfs(x - 1, y, 1);
        }

        // try go right
        if (x + 1 >= n || used[x + 1][y] || g[x + 1][y] == 0)
        {
            //cout << "no!" << (x + 1 >= n) << ", " << (used[x + 1][y]) << ", " << (g[x + 1][y] == 0) << endl;
        }
        else // right boundary
        {
            //cout << "can go right\n";
            if (g[x + 1][y] == 1) // right is a line
                dfs(x + 1, y, 0);
            else
                dfs(x + 1, y, 1);
        }
    }
    else // d == 1; blank = 0, line = 1, turn = 2
    {
        // try to go up
        if (y - 1 < 0 || used[x][y - 1] || g[x][y - 1] == 0)
        {
        }
        else
        {
            //cout << "can go up\n";
            if (g[x][y - 1] == 1)
                dfs(x, y - 1, 1);
            else
                dfs(x, y - 1, 0);
        }

        // try to go down
        if (y + 1 >= m || used[x][y + 1] || g[x][y + 1] == 0)
        {
        }
        else
        {
            //cout << "can go down\n";
            if (g[x][y + 1] == 1)
                dfs(x, y + 1, 1);
            else
                dfs(x, y + 1, 0);
        }
    }
    used[x][y] = 0;
}

int main()
{
    int cases;
    char tmp;
    cin >> cases;
    while (cases--)
    {
        ans = 0;
        cin >> m >> n; // g[m][n]
        used = new bool *[n];
        g = new int *[n];
        for (int i = 0; i < n; i++)
        {
            used[i] = new bool[m];
            g[i] = new int[m];
            memset(used[i], 0, sizeof(bool) * m);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> tmp;
                switch (tmp)
                {
                case 'L':
                    g[j][i] = 1;
                    break;
                case 'B':
                    g[j][i] = 0;
                    break;
                case 'T':
                    g[j][i] = 2;
                    break;
                default:
                    cout << "error input\n";
                }
            }
        }
        if (g[0][0] == 0)
        {
            ans = 0;
        }
        else
        {
            dfs(0, 0, 0);
            dfs(0, 0, 1);
        }
        cout << "Number of legal solutions: " << ans << endl;
    }
}