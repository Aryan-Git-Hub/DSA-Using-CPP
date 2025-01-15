#include<iostream>
using namespace std;

int getSum(int *arr, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int n;
    cout<<"Enter the size of array you wanna create: ";
    cin>>n;
    
    //variable size array
    int* arr = new int[n]; // static memory = sizeof(int*) = 8; dynamic memory = 4*n
    // new int --> will return address of memory, isiliye hum ise pointer se point krte hai
    cout<<sizeof(arr)<<endl; // give only static memory size

    //taking input in aray
    cout<<"Enter values in array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    int ans = getSum(arr, n);
    cout<<"answer is "<<ans<<endl;

    delete []arr;

    return 0;
}