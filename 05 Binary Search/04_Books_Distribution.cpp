// 1. Book Allocation
    // (a) Every student get at least 1 Book
    // (b) Books will be allocated in contiguous way
    // (c) Out of all permutation student with most number of books get min pages
// 2. Painter Partition -> divide the no. of painters to paint given lengths of wall in such a way to complete paint all the walls in shortest time. (same strategy as in Book Allocation)
#include<iostream>
using namespace std;

int max(int* arr, int n) {
    int m = arr[0];
    for (int i = 0; i < n; i++) if (m<arr[i]) m = arr[i];
    return m;
}

int sum(int* arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int main() {
    int books = 4, stu = 2;
    int arr[4] = {12, 34, 67, 90};
    int start = max(arr, books), mid, end = sum(arr, books), ans;
    
    while(start<=end) {
        mid = (start+end)/2;
        int page = 0, count = 1;
        for (int i = 0; i < books; i++)
        {
            page += arr[i];
            if (page>mid)
            {
                count++;
                page = arr[i];
            }
        }
        if (count<=stu)
        {
            ans = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    cout<<"Answer is "<<ans;

    return 0;
}