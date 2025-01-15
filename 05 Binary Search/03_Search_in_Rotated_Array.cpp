// 'Kth' Missing Positive Integer
#include<iostream>
using namespace std;

int main() {
    int n = 6;
    int arr[6] = {4, 5, 0, 1, 2, 3};
    int start = 0, mid, end = n-1, key, index = -1;
    cout<<"Enter the number you wanna find: ";
    cin>>key;

    while(start<=end) {
        mid = (start+end)/2;
        if (key==arr[mid]){
            index = mid;
            break;
        }
        else if (arr[start]<=arr[mid]){
            if (key>=arr[start] && key<=arr[mid]) end = mid-1;
            else start = mid+1;
        }
        else {
            if(key>=arr[mid] && key<=arr[end]) start = mid+1;
            else end = mid-1;
        }
    }

    cout<<"Index of "<<key<<" is "<<index;

    return 0;
}