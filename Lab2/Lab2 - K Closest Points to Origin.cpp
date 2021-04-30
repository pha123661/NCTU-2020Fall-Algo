#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct
{
    int x, y, dis;
} point_data;

bool compare_dis(point_data a, point_data b)
{
    return a.dis < b.dis;
}

bool compare_x(point_data a, point_data b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

int main()
{
    int n, k;
    vector<point_data> point_set, smallest_k;
    point_data tmpp;
    cin >> n >> k;
    while (n--)
    {
        scanf("%d %d", &(tmpp.x), &(tmpp.y));
        tmpp.dis = tmpp.x * tmpp.x + tmpp.y * tmpp.y;
        point_set.push_back(tmpp);
    }
    sort(point_set.begin(), point_set.end(), compare_dis);
    for (int i = 0; i < k; i++)
    {
        smallest_k.push_back(point_set[i]);
    }
    sort(smallest_k.begin(), smallest_k.end(), compare_x);
    for (int i = 0; i < k; i++)
    {
        printf("%d %d\n", smallest_k[i].x, smallest_k[i].y);
    }
    return 0;
}