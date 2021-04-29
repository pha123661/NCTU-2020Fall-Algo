#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int bfind(int *arr, int target, int lpos, int rpos)
{
    if (lpos > rpos)
        return -1;
    int mid = (lpos + rpos) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return bfind(arr, target, lpos, mid - 1);
    if (arr[mid] < target)
        return bfind(arr, target, mid + 1, rpos);
    return -1;
}

int main()
{
    int m, n, cases;
    cin >> m >> n >> cases;
    int **arr = new int *[m];
    int *first_col = new int[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &(arr[i][j]));
        }
        first_col[i] = arr[i][0];
    }
    while (cases--)
    {
        int num;
        pair<int, int> ans; //first = row , second = col;
        scanf("%d", &num);
        for (int i = m - 1; i >= 0; i--)
        {
            if (first_col[i] <= num)
            {
                ans.first = i;
                break;
            }
        }
        ans.second = bfind(arr[ans.first], num, 0, n - 1);
        if (ans.second == -1)
            cout << "-1\n";
        else
            cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}