#include<iostream>
using namespace std;

int main() {
    int n, start = 0, end, mid, sqrt;
    cout<<"Enter any number: ";
    cin>>n;
    end = n;
    mid = n/2;

    while (start<=end)
    {
        if (mid*mid>n) end = mid-1;
        else if (mid*mid<n) {
            start = mid+1;
            sqrt = mid;
        } else {
            sqrt = mid;
            break;
        }
        mid = (start+end)/2;
    }
    cout<<"Square root of "<<n<<" is "<<sqrt;

    return 0;
}