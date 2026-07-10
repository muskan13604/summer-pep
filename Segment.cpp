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
    segment_array[i] = segment_array[2 * i + 1] * segment_array[2 * i + 2];
}

void point_update(int i, int low, int high, int index, int value, vector<int>& segment_array) {
    if(low == high){
        segment_array[i] = value;
        return;
    }
    int mid = (low + high) / 2;
    if (index <= mid){
        point_update(2 * i + 1, low, mid, index, value, segment_array);
    }
    else{
        point_update(2 * i + 2, mid + 1, high, index, value, segment_array);
    }
    segment_array[i] = segment_array[2 * i + 1] * segment_array[2 * i + 2];
}



int main() {
    int arr[] = {2, 0, 4, 5, 9, 0, -1, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> segment_array(4*n, 0);
    int low = 0;
    int high = n - 1;
    int index = 0;
    build_segment_tree(index, arr, n, low, high, segment_array);
    for(int i = 0; i < 4 * n; i++) {
        cout << segment_array[i] << " ";
    }

    point_update(0, low, high, 1, 7, segment_array);
    arr[1] = 7;

    point_update(0, low, high, 5, 7, segment_array);
    arr[5] = 7;

    point_update(0, low, high, 7, 5, segment_array);
    arr[7] = 5; 

    // update array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

// update segment tree
     for (int i = 0; i < 4 * n; i++) {
        cout << segment_array[i] << " ";
    }


    return 0;
}