// Binary search
#include<iostream>
using namespace std;

int main() {
    int n, key, mid, start = 0, end, index = -1;
    cout<<"Enter the size of array: ";
    cin>>n;
    int* arr = new int[n];
    // taking values
    cout<<"Enter values in array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Which element you wanna find? ";
    cin>>key;

    end = n-1;
    mid = n/2;
    while (start<=end)
    {
        if (arr[mid]<key) start = mid+1;
        else if (arr[mid]>key) end = mid-1;
        else {
            index = mid;
            break;
        }
        mid = (start+end)/2;
    }

    cout<<"Index of "<<key<<" is "<<index;


    return 0;
}