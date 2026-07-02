#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (target > arr[mid])
            high = mid - 1;

        else
            low = mid + 1;    
    }

    return -1;
}

int main() {
    int arr[] = {25, 20, 18, 12, 11, 9, 8, 7, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    cout << binarySearch(arr, n, target);
}