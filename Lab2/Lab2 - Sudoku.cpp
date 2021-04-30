#include <bits/stdc++.h>
using namespace std;

#define EMPTY_BOX (0)

int N, partition_size; // dim of shudu , dim of partition
int shudu[25][25];     // shudu

bool is_in_partition(int num, int row, int col);

bool not_used(int num, int row, int col)
{
    /*if (shudu[row][col] != EMPTY_BOX)
        return false;*/
    for (int i = N - 1; i >= 0; i--) //if in col or not
    {
        if (shudu[i][col] == num)
            return false;
        if (shudu[row][i] == num)
            return false;
    }
    if (is_in_partition(num, row, col)) // if in partition or not
        return false;
    return true;
}

bool find_empty(int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = N - 1; col >= 0; col--)
        {
            if (!shudu[row][col])
                return true;
        }
    }
    return false; // solved!!
}

bool solve_shudu()
{
    int row, col;
    if (!find_empty(row, col)) // call by reference , init by function (~= return pair)
        return true;
    for (int num = 9; num >= 1; num--) // try 1~9
    {
        if (not_used(num, row, col))
        {
            shudu[row][col] = num; // try try see
            if (solve_shudu())
                return true;
            //reach here if failed;
            shudu[row][col] = EMPTY_BOX;
        }
    }
    // reach here if 1~9 failed -> backtrack
    return false;
}

void print_shudu();

int main()
{
    //input
    string tmp;
    getline(cin, tmp);
    switch (tmp.size())
    {
    case 7:
        N = 4;
        partition_size = 2;
        break;
    case 17:
        N = 9;
        partition_size = 3;
        break;
    case 31:
        N = 16;
        partition_size = 4;
        break;
    case 49:
        N = 25;
        partition_size = 5;
        break;
    default:
        cout << "error : first line = " << tmp << endl;
    }
    stringstream ss(tmp);
    for (int i = 0; i < N; i++)
    {
        ss >> shudu[0][i];
    }
    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> shudu[j][i];
        }
    }
    //solve
    bool ans;

    ans = solve_shudu();
    //output
    if (ans)
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N - 1; col++)
            {
                cout << shudu[row][col] << " ";
            }
            cout << shudu[row][N - 1] << endl;
        }
    else
        cout << "NO\n";
    cout << endl;
    return 0;
}

bool is_in_partition(int num, int row, int col)
{
    int partition_row = row - row % partition_size; // which partition
    int partition_col = col - col % partition_size;
    for (int i = 0; i < partition_size; i++)
    {
        for (int j = 0; j < partition_size; j++)
        {
            if (shudu[i + partition_row][j + partition_col] == num)
                return true;
        }
    }
    return false;
}