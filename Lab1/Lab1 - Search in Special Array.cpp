#include <bits/stdc++.h>
using namespace std;

int rotate__;

int bfind(vector<int> &nums, int target, int lpos, int rpos)
{
    int mid = (lpos + rpos) / 2;
    if (rpos < lpos)
        return -1;
    if (target == nums[mid])
        return mid;
    if (target > nums[mid])
        return bfind(nums, target, mid + 1, rpos);
    if (target < nums[mid])
        return bfind(nums, target, lpos, mid - 1);
}

int find_rotate(vector<int> &nums, int lpos, int rpos)
{
    int mid = lpos + ((rpos - lpos) / 2);
    if (rpos < lpos)
        return -1;
    if (rpos == lpos)
        return lpos;
    if (mid < rpos && nums[mid] > nums[mid + 1])
        return mid;
    if (mid > lpos && nums[mid] < nums[mid - 1])
        return mid - 1;
    if (nums[mid] <= nums[lpos])
        return find_rotate(nums, lpos, mid - 1);
    else
        return find_rotate(nums, mid + 1, rpos);
}

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // write your method here
        int idx;
        if (nums[0] <= target && target <= nums[rotate__])
            idx = bfind(nums, target, 0, rotate__);
        else
        {
            idx = bfind(nums, target, rotate__ + 1, nums.size() - 1);
        }
        return idx;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int tmp;
    vector<int> v;
    Solution sol;
    cin >> M >> N;

    while (M--)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    rotate__ = find_rotate(v, 0, v.size() - 1);
    while (N--)
    {
        cin >> tmp;
        cout << sol.search(v, tmp) << endl;
    }

    return 0;
}