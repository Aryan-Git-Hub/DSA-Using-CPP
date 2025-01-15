#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr = new int[n];
    // Inserting elements
    cout<<"Enter elements in array: ";
    for (int i = 0; i < n; i++) cin>>arr[i];

    // Main code
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

    cout<<"Array after sorting: ";
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

    delete []arr;

    return 0;
}