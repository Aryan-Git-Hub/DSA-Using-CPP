#include<iostream>
using namespace std;

int main() {
    int* a;          // pointer to int
    char** ppc;       // pointer to pointer to char
    int* ap[15];      // array of 15 pointers to ints
    int (*fp)(char*); // pointer to function taking a char* argument; returns an int
    int* f(char*);    // function taking char* argument; returns a pointer to int


    return 0;
}