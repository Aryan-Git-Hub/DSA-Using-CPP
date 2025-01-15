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
    int min_index;
    for (int i = 0; i < n-1; i++)
    {
        min_index = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min_index]>arr[j]) min_index = j;
        } swap(arr[i], arr[min_index]);
    }

    cout<<"Array after sorting: ";
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

    delete []arr;

    return 0;
}