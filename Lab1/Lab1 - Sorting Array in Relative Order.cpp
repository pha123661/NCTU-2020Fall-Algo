#include <bits/stdc++.h>
using namespace std;

int bfind(int *arr, int target, int lpos, int rpos)
{
    if (lpos > rpos)
        return -1;
    int mid = (lpos + rpos) / 2;
    if ((mid == 0 && arr[mid] == target) || (arr[mid] == target && (arr[mid - 1] < arr[mid]))) //確定是最左
        return mid;
    if (target > arr[mid])
        return bfind(arr, target, mid + 1, rpos);
    if (target < arr[mid])
        return bfind(arr, target, lpos, mid - 1);
    return bfind(arr, target, lpos, mid - 1);
}

void strange_sort(int *ar1, int *ar2, int l1, int l2)
{
    int *sorted_ar1, *mark_ar1;
    sorted_ar1 = new int[l1];
    mark_ar1 = new int[l1];
    memset(mark_ar1, 0, sizeof(mark_ar1));
    for (int i = 0; i < l1; i++)
        sorted_ar1[i] = ar1[i];
    sort(sorted_ar1, sorted_ar1 + l1);
    int ans_idx = 0, idx;
    for (int i = 0; i < l2; i++)
    {
        idx = bfind(sorted_ar1, ar2[i], 0, l1 - 1); //finding idx of left most target
        if (idx == -1)
            continue; //要在最後
        for (int j = idx; j < l1 && sorted_ar1[j] == ar2[i]; j++)
        {
            ar1[ans_idx++] = sorted_ar1[j];
            mark_ar1[j] = 1;
        }
    }
    for (int i = 0; i < l1; i++)
    {
        if (!mark_ar1[i])
            ar1[ans_idx++] = sorted_ar1[i];
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int l1, l2;
        int *ar1, *ar2;
        cin >> l1 >> l2;
        ar1 = new int[l1];
        ar2 = new int[l2];
        for (int i = 0; i < l1; i++)
        {
            scanf("%d", ar1 + i);
        }
        for (int i = 0; i < l2; i++)
        {
            scanf("%d", ar2 + i);
        }
        strange_sort(ar1, ar2, l1, l2);
        for (int i = 0; i < l1; i++)
        {
            if (i)
                printf("%c", ' ');
            printf("%d", ar1[i]);
        }
        cout << endl;
    }
    return 0;
}