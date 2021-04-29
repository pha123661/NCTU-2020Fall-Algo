#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool greater_or_eq(string a, string b)
{

    string ab, ba;
    ab = a + b;
    ba = b + a;
    //cout << "ab = " << ab << "  ba = " << ba << endl;
    for (int i = 0; i < ab.size(); i++)
    {
        if (ab[i] > ba[i])
        {
            //cout << "1\n";
            return 1;
        }
        else if (ba[i] > ab[i])
        {
            //cout << "0\n";
            return 0;
        }
    }
    return 1;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int num;
        string tmp;
        vector<string> ans;
        cin >>
            num;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            ans.push_back(tmp);
        }
        bool changed = 1;
        sort(ans.begin(), ans.end(), greater_or_eq);
        for (auto str : ans)
            cout << str;
        cout << endl;
    }
    return 0;
}