#include<iostream>
using namespace std;

int main() {
    char arr1[5] = {97, 98, 99, 0};
    for (int i = 0; i < 4; i++)
    {
        cout<<arr1[i]<<endl; // char(0) -> NULL character('\0')
    }
    
    int arr2[8] = {1, 2, 3, 4};
    // arr2 is equivalent to arr3
    // 0 as a null value automatically assigned to remaining space
    int arr3[8] = {1, 2, 3, 4, 0, 0, 0, 0};

    bool a = char(0)=='\0';
    cout<<a; // 1(true)

    return 0;
}