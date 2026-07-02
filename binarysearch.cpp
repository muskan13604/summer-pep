#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int t) {

    // Base Case
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;

    if (arr[mid] == t)
        return mid;


    if (t > arr[mid])
        return binarySearch(arr, l, mid - 1, t);

    return binarySearch(arr, mid + 1, h, t);
}

int main() {
    int arr[] = {25, 20, 18, 12, 11, 9, 8, 7, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 20;

    cout << binarySearch(arr, 0, n - 1, target);
}