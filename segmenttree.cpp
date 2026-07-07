#include<iostream>
#include<vector>
using namespace std;

void build_segment_tree(int i, int arr[], int n, int low, int high, vector<int>& segment_array) {
    if (low == high) {
        segment_array[i] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build_segment_tree(2 * i + 1, arr, n, low, mid, segment_array);
    build_segment_tree(2 * i + 2, arr, n, mid + 1, high, segment_array);
    segment_array[i] = segment_array[2 * i + 1] + segment_array[2 * i + 2];
}

int main() {
    int arr[] = {6, 7, 2, 1, 4, 0, 5, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> segment_array(4*n, 0);
    int low = 0;
    int high = n - 1;
    int index = 0;
    build_segment_tree(index, arr, n, low, high, segment_array);
    for (int i = 0; i < 4 * n; i++) {
        cout << segment_array[i] << " ";
    }
    return 0;
}