
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int index, int k, int last, int min)
{
    if(k == 0)
        return min;

    if(index == arr.size())
        return -1;

    int skip = solve(arr, index + 1, k, last, min);
    int take;

    if(last == -1)
    {
      take = solve(arr, index + 1, k - 1, arr[index], INT_MAX);
    }
    else
    {
        int distance = arr[index] - last;
        take = solve(arr,index + 1,k - 1,arr[index],min(min, distance));
    }

    return max(take, skip);
}

int main()
{
    vector<int> arr = {2, 4, 5, 9, 11, 15, 18, 27, 31};

    int k = 4;

    cout << solve(arr, 0, k, -1, INT_MAX);

    return 0;
}