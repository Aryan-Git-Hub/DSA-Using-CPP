#include<iostream>
using namespace std;

int binarySearch(int* arr, int key, int start, int end) {
    if (start>end) return -1;
    int mid = (start+end)/2;
    if (arr[mid]==key) return mid;
    else if(key<arr[mid]) end = mid-1;
    else start = mid+1;
    return binarySearch(arr, key, start, end);
}

int main() {
    int key = 8, start = 0, end = 9;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<binarySearch(arr, key, start, end)<<endl;

    return 0;
}