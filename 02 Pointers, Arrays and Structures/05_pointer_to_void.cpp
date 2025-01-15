#include<iostream>
using namespace std;

int main() {
    // pointer to void
    int a = 10;
    void* ptr = &a;
    cout<<*(int*)ptr<<endl; // we must have to typecast the void pointer to its original datatype to use it

    // malloc, calloc returns a void pointer, isiliye uske syntax me hume pehle type-cast krna padhta hai
    int* p = (int*)malloc(4*sizeof(int)); // dynamic memory allocation using malloc
    int* q = new int; // another method to create dynamic memory and using heap memory instead of stack memory
    cout<<sizeof(p)<<endl;
    *q = 55;
    cout<<*q<<endl;
    // size of q is sizeof(int*)+sizeof(int) = 8+4 = 12
    cout<<sizeof(q)<<endl; // it returns only size in stack memory which is sizeof(int*)

    // to release dynamic memory
    free(p);
    delete q;
    // you can learn more about dynamic memory in chapter 3

    return 0;
}