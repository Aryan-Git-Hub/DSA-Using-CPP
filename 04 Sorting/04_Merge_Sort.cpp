#include<iostream>
using namespace std;

void merge(int* arr, int start, int mid, int end) {
    vector<int> temp(end-start+1);
    int left = start, right = mid+1, index = 0;

    while (left<=mid && right<=end)
    {
        if (arr[left]<=arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        } else {
            temp[index] = arr[right];
            index++, right++;
        }
    }
    
    // when element left in left array
    while (left<=mid) {
        temp[index] = arr[left];
        left++, index++;
    }
    // when element left in right array
    while (right<=end) {
        temp[index] = arr[right];
        right++, index++;
    }
    
    // putting elements from temp to arr
    index = 0;
    while (start<=end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
    
}

void mergeSort(int* arr, int start, int end) {
    if (start>=end) return;
    
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    
    merge(arr, start, mid, end);
}

int main() {
    int arr[10] = {5, 3, 7, 6, 2, 8, 4, 1, 9, 0};
    int n = 10;
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}