#include <iostream>
#include <string>
using namespace std;

string parse(string a)
{
    if (a.size() == 0)
        return a;
    if (a.size() % 2)
        return a;
    string a1 = parse(a.substr(0, a.size() / 2));
    string a2 = parse(a.substr(a.size() / 2));
    return min(a1 + a2, a2 + a1);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string a, b;
        bool ans;
        cin >> a >> b;
        a = parse(a);
        b = parse(b);
        ans = (a == b);
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}