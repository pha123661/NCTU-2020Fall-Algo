#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

void radix_sort(string a, char *buffer)
{
    int bucket[123] = {0}; // 'z' = 122, 'a' = 97
    for (char c : a)
    {
        bucket[c]++;
        if ((int)c < 97)
        {
            int *a = NULL;
            *a = 1;
        }
    }
    int pos = 0;
    for (int i = 97; i <= 122; i++)
    {
        while (bucket[i]--)
        {
            buffer[pos++] = (char)i;
        }
    }
}

void greater_radix_sort(string a, char *buffer)
{
    int bucket[123] = {0}; // 'z' = 122, 'a' = 97
    for (char c : a)
    {
        bucket[c]++;
    }
    int pos = 0;
    for (int i = 122; i >= 97; i--)
    {
        while (bucket[i]--)
        {
            buffer[pos++] = (char)i;
        }
    }
}

int main()
{
    int cases;
    string tmp;
    cin >> cases;
    getline(cin, tmp); // \n
    while (cases--)
    {
        string str_a, str_b;
        getline(cin, str_a);
        getline(cin, str_b);
        char *a = new char[str_a.size() + 1];
        char *b = new char[str_b.size() + 1];
        char *ans = new char[str_a.size() + 1];
        radix_sort(str_a, a);
        greater_radix_sort(str_b, b);

        int len = str_a.size();
        int begin_a = 0, end_a;
        int begin_b = 0, end_b;
        if (len % 2) // odd
        {
            end_a = len / 2;
            end_b = len / 2 - 1;
        }
        else
        {
            end_a = len / 2 - 1;
            end_b = len / 2 - 1;
        }

        if (len == 1)
        {
            end_a = end_b = 0;
        }

        int begin_ans = 0, end_ans = len - 1;
        bool turn_a = 1;
        bool put_end = 0;
        // put front
        for (int i = 0; i < len; i++)
        {
            if (a[begin_a] >= b[begin_b])
                break;
            if (turn_a)
            {
                ans[begin_ans++] = a[begin_a++];
            }
            else
            {
                ans[begin_ans++] = b[begin_b++];
            }
            turn_a = !turn_a;
        }

        // put back
        for (end_ans = len - 1; end_ans >= begin_ans; end_ans--)
        {
            if (turn_a)
            {
                ans[end_ans] = a[end_a--];
            }
            else
            {
                ans[end_ans] = b[end_b--];
            }

            turn_a = !turn_a;
        }
        ans[len] = '\0';
        puts(ans);
    }
}