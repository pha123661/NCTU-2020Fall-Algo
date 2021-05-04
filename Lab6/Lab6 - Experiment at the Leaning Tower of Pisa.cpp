#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

// LeetCode 887
// 公式解：https://leetcode.com/problems/super-egg-drop/discuss/181702/Clear-C%2B%2B-codeRuntime-0-msO(1)-spacewith-explation.No-DPWhat-we-need-is-mathematical-thought!

int helper(int x, int k, int n)
{
    int rst = 0, tmp = 1;
    for (int i = 1; i <= k && rst < n; i++)
    {
        tmp = tmp * (x - i + 1) / i;
        rst += tmp;
    }
    return rst;
}

int ball_drop(int k, int n)
{
    int low = 1, high = n;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (helper(mid, k, n) < n)
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    while (cin >> k >> n && (n || k))
    {
        cout << ball_drop(k, n) << "\n";
    }
}