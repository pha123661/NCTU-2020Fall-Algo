#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int find_size(vector<int> &stus)
{
    if (stus.size() == 1)
        return 0;
    if (stus.size() == 2)
        return 1;
    sort(stus.begin(), stus.end());
    pair<int, int> max1;                     //first =  # , second = value;
    int tmp1 = stus[0], tmp2 = 0, kinds = 1; //tmp1 = value , tmp2 = #;
    max1.first = 0;
    for (int i = 0; i < stus.size(); i++)
    {
        if (tmp1 == stus[i])
        {
            tmp2++;
        }
        else
        {
            if (tmp2 >= max1.first)
            {
                max1.first = tmp2;
                max1.second = tmp1;
            }
            tmp1 = stus[i];
            tmp2 = 1;
            kinds++;
        }
    }
    //last update
    if (tmp2 >= max1.first)
    {
        max1.first = tmp2;
        max1.second = tmp1;
    }
    // min(kinds-1 , # of max1)
    if (max1.first > kinds)
    {
        return min(max1.first, kinds); //ex:[1,2,3] ; [3,3,3]
    }
    else
    {
        return min(max1.first, kinds - 1);
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int nums, tmp;
        vector<int> stus;
        scanf("%d", &nums);
        for (int i = 0; i < nums; i++)
        {
            scanf("%d", &tmp);
            stus.push_back(tmp);
        }
        cout << find_size(stus) << endl;
    }
    return 0;
}