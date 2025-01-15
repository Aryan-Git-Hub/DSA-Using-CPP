#include<iostream>
using namespace std;

int add(int a, int b) {
    return a+b;
}

int main() {
    int (*ptr)(int, int); // ptr points to a function having two arguments of integer type and it return integer value
    ptr = &add; // or ptr = &add; because add represent initial address of itself
    int result = (*ptr)(10, 20);
    cout<<result<<endl;
    // Another method ptr = add; because add represent initial address of itself
    ptr = add;
    result = ptr(10,20);
    cout<<result<<endl;


    return 0;
}