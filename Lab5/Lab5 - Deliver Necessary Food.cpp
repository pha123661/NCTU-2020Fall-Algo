#include <bits/stdc++.h>
#include <cstring>
#include <cmath>
using namespace std;

struct family
{
    int a, b;
    int sub;
};

bool my_compare(const struct family a, const struct family b)
{
    return abs(a.sub) > abs(b.sub);
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
        int tmp1, tmp2;
        cin >> n;
        vector<struct family> sets;
        struct family tmp3;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp1 >> tmp2;
            tmp3.a = tmp1;
            tmp3.b = tmp2;
            tmp3.sub = tmp1 - tmp2;
            sets.push_back(tmp3);
        }
        sort(sets.begin(), sets.end(), my_compare);

        int cap_a = 0, cap_b = 0;
        int ans = 0;
        n = n / 2;
        for (auto f : sets)
        {
            if (f.sub < 0) // a
            {
                if (cap_a < n)
                {
                    cap_a++;
                    ans += f.a;
                }
                else
                {
                    cap_b++;
                    ans += f.b;
                }
            }
            else // b
            {
                if (cap_b < n)
                {
                    cap_b++;
                    ans += f.b;
                }
                else
                {
                    cap_a++;
                    ans += f.a;
                }
            }
        }
        cout << ans << "\n";
    }
}