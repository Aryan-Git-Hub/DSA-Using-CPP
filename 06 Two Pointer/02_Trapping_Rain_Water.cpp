// Trapping Rain water
#include<iostream>
using namespace std;

int max_index(int* arr, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) if (arr[m]<arr[i]) m = i;
    return m;
}

int main() {
    // Input
    int n = 8;
    int arr[8] = {4, 2, 0, 5, 2, 6, 2, 3};
    
    int water = 0, prefix = 0, suffix = 0, greatest_index = max_index(arr, n);
    for (int i = 0; i < greatest_index; i++)
    {
        if (prefix-arr[i]<0) {
            prefix = arr[i];
        }
        else water += prefix-arr[i];
    }
    
    for (int i = n-1; i > greatest_index; i--)
    {
        if (suffix-arr[i]<0) {
            suffix = arr[i];
        }
        else water += suffix-arr[i];
    }
    
    cout<<"Answer is "<<water<<endl;

    return 0;
}