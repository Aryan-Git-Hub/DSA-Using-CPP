#include<iostream>
using namespace std;

int main() {
    char c[] = "hello";
    char* p = c;
    cout<<p<<endl; // it will print the whole string
    cout<<*p<<endl; // it will print the first character of the string
    cout<<*(p+1)<<endl; // it will print the second character of the string
    cout<<p[1]<<endl; // it will print the second character of the string
    cout<<p<<endl; // it will print the whole string
    cout<<p+1<<endl; // it will print the string from second character

    // to find address of each character of the string
    cout<<(void*)p<<endl;
    cout<<(void*)(p+1)<<endl;


    return 0;
}