#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

class graph
{
public:
    int vertics_num;
    list<int> *adjacency_list;
    void topologicalsort(int v, bool visted[], queue<int> &stack); // "queue" is for reversed stack
    graph(int n);
    void add_edge(int src, int dest);
    bool is_loop(int idx);
    bool loop_detection(int v, bool *visited, bool *in_this_round);
    void solver(int idx);
};

graph ::graph(int n)
{
    this->vertics_num = n;
    adjacency_list = new list<int>[n];
}

void graph ::add_edge(int src, int dest)
{
    adjacency_list[src].push_back(dest);
}

void graph::topologicalsort(int v, bool visited[], queue<int> &stack)
{
    visited[v] = 1;
    for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end(); it++)
    {
        if (visited[*it])
            continue;
        topologicalsort(*it, visited, stack);
    }
    stack.push(v);
}

bool graph::loop_detection(int v, bool *visited, bool *in_this_round)
{
    if (visited[v])
    {
        in_this_round[v] = 0;
        return false;
    }
    visited[v] = 1;
    in_this_round[v] = 1;
    for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end(); it++)
    {
        if (!visited[*it] && loop_detection(*it, visited, in_this_round)) //
            return true;
        else if (in_this_round[*it])
            return true;
    }
    in_this_round[v] = 0;
    return false;
}

bool graph ::is_loop(int idx)
{
    bool *visited = new bool[vertics_num];
    bool *in_this_round = new bool[vertics_num];
    memset(visited, 0, sizeof(bool) * vertics_num);
    memset(in_this_round, 0, sizeof(bool) * vertics_num);
    if (loop_detection(idx, visited, in_this_round))
        return true;
    return false;
}

void graph::solver(int idx)
{
    queue<int> trace;
    bool *visited = new bool[vertics_num];
    memset(visited, 0, sizeof(bool) * vertics_num);
    topologicalsort(idx, visited, trace);
    bool flag = 0;
    while (!trace.empty())
    {
        if (flag)
            cout << ' ';
        cout << trace.front();
        trace.pop();
        flag = 1;
    }
    cout << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++)
    {
        int n, k, dest;
        int tmp1, tmp2;
        cin >> n >> k >> dest;
        graph p(n);
        for (int i = 0; i < k; i++)
        {
            cin >> tmp1 >> tmp2;
            p.add_edge(tmp2, tmp1);
        }
        if (fork() == 0)
        {
            if (p.is_loop(dest))
            {
                cout << "Lion can not pass this chapter!" << endl;
                continue;
            }
            p.solver(dest);
        }
        else
        {
            wait(NULL);
        }
    }
}