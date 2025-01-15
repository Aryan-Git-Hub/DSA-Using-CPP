#include<iostream>
using namespace std;

int* bubble_sort(int* arr, int n) {
    int* ptr;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j+1]<arr[j])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    ptr = arr;
    return ptr;
}

int main() {
    int n = 5;
    // int stalls[5] = {1, 2, 4, 8, 9};
    int stalls[5] = {10, 1, 2, 7, 5};
    int* stalls_ptr = bubble_sort(stalls, n);
    int start = 1, end = stalls_ptr[n-1]-stalls_ptr[0], mid, ans, no_of_cows = 3;

    while (start<=end)
    {
        mid = (start+end)/2;
        int  just_greater= stalls_ptr[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (just_greater+mid<=stalls_ptr[i]) {
                just_greater = stalls_ptr[i];
                count++;
            }
        }
        if (count<no_of_cows) end = mid-1;
        else {
            ans = mid;
            start = mid+1;
        }
    }
    cout<<"Answer is "<<ans;

    return 0;
}