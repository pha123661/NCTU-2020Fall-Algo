#include <bits/stdc++.h>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int num1, num2, num3, num4, num5, num6;
    while (cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 && (num1 + num2 + num3 + num4 + num5 + num6))
    {
        int ans = 0;
        ans = ans + num6 + num5 + num4; // each carton only fits one of those
        // 5*5
        num1 -= min(num1, num5 * 11); // each 5*5 box leaves 11 1*1 space
        // 4*4
        if (num2 < num4 * 5)                          // each 4*4 box leaves 5 2*2 space
            num1 -= min(num1, (num4 * 5 - num2) * 4); // puts 1*1 box in spare 2*2 space
        num2 -= min(num2, num4 * 5);
        // 3*3
        ans += ceil(num3 / 4.0);
        num3 %= 4;
        switch (num3) // 3 kinds of spare;
        {
        case 0:
            break;
        case 1:
            // 6*6 - 3*3 space can put 5 2*2 box + 7 1*1 box
            if (num2 < 5)
                num1 -= min(num1, (5 - num2) * 4); // convert 2*2 to 4 1*1
            num1 -= min(num1, 7);
            num2 -= min(num2, 5);
            break;
        case 2:
            // 6*6 - 6*3 space can put 3 2*2 + 6 1*1
            if (num2 < 3)
                num1 -= min(num1, (3 - num2) * 4);
            num1 -= min(num1, 6);
            num2 -= min(num2, 3);
            break;
        case 3:
            // can put 1 2*2 + 5 1*1
            if (num2 < 1)
                num1 -= min(num1, 4);
            num1 -= min(num1, 5);
            num2 -= min(num2, 1);
            break;
        }
        // if any 2*2 remains
        ans += ceil(num2 / 9.0);
        num2 %= 9;
        if (num2) // spare for 1*1
            num1 -= min(num1, (9 - num2) * 4);
        // if any 1*1 remains
        ans += ceil(num1 / 36.0);
        cout << ans << "\n";
    }
}