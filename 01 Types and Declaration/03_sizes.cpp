#include<iostream>
using namespace std;

int main() {
    cout<<"Size of 'char' in bytes is: "<<sizeof(char)<<endl;
    cout<<"Size of 'bool' in bytes is: "<<sizeof(bool)<<endl;
    cout<<"Size of 'wchar_t' in bytes is: "<<sizeof(wchar_t)<<endl; // wide character literals
    cout<<"Size of 'short' in bytes is: "<<sizeof(short)<<endl;
    cout<<"Size of 'int' in bytes is: "<<sizeof(int)<<endl;
    cout<<"Size of 'float' in bytes is: "<<sizeof(float)<<endl;
    cout<<"Size of 'double' in bytes is: "<<sizeof(double)<<endl;
    cout<<"Size of 'long' in bytes is: "<<sizeof(long)<<endl;
    cout<<"Size of 'long double' in bytes is: "<<sizeof(long double)<<endl;
    cout<<"Size of 'signed' in bytes is: "<<sizeof(signed)<<endl;
    cout<<"Size of 'unsigned' in bytes is: "<<sizeof(unsigned)<<endl;

    return 0;
}