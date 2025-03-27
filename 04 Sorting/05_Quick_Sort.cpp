#include<iostream>
using namespace std;

int partition(int* arr, int start, int end) {
    int pos = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i]<=arr[end])
        {
            swap(arr[pos], arr[i]);
            pos++;
        }
    }
    return pos-1;
}

void quickSort(int* arr, int start, int end) {
    if (start>=end) return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}


int main() {
    int arr[10] = {5, 3, 7, 6, 2, 8, 4, 1, 9, 0};
    int n = 10;
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}