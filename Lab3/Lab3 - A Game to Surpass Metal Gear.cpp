#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool *visited;

bool DFS(vector<int> &deck, int idx)
{
    int direction[2];
    direction[0] = idx - deck[idx];
    direction[1] = idx + deck[idx];
    for (int i = 0; i < 2; i++)
    {
        if (direction[i] < 0 || direction[i] >= deck.size())
            continue;
        if (visited[direction[i]])
            continue;
        visited[direction[i]] = true;
        if (deck[direction[i]] == 0)
            return true;
        if (DFS(deck, direction[i]))
            return true;
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, start_idx;
        int tmp;
        vector<int> deck;
        cin >> n >> start_idx;
        visited = new bool[n];
        memset(visited, 0, sizeof(bool) * n);
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            deck.push_back(tmp);
        }
        bool ans = DFS(deck, start_idx);
        if (ans)
        {
            cout << "We will watch your career with great interest." << endl;
        }
        else
        {
            cout << "My disappointment is immeasurable, and my day is ruined." << endl;
        }
    }
    return 0;
}