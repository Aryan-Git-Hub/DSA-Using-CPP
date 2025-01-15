#include<iostream>
using namespace std;

int main() {
    int n = 11;
    int arr[11] = {2, 5, 5, 5, 2, 5, 6, 5, 8, 5, 8};
    int res = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (count==0) {
            res = arr[i];
            count++;
        }
        else {
            if (res==arr[i]) count++;
            else count--;
        }
    }
    cout<<"Result is "<<res<<endl;    

    return 0;
}