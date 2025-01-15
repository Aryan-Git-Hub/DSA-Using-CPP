// Declaration - Telling the compiler about the variable (No space reserved)
// Definition - Declaration + space reservation
#include<iostream>
using namespace std;

int a;

int main() {
    int b;
     cout<<a<<endl; // 'a' is global variable and initialized by 1
     cout<<b<<endl; // 'b' is local or functional variable and having garbage value i.e. random value

    unsigned char a;
    typedef unsigned char uchar;
    uchar b; // here definition of both a and b are same, since typedef can be a convenient shorthand for a type with an unwidely name


    return 0;
}