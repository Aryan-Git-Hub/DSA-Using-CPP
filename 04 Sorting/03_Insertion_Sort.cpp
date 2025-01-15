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
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(arr[j-1]>arr[j]) swap(arr[j-1], arr[j]);
        }
    }
    
    cout<<"Array after sorting: ";
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

    delete []arr;

    return 0;
}