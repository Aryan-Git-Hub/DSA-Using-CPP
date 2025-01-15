#include<iostream>
using namespace std;

int main() {
    // const variables and its pointer
    const double pi = 3.14;
    // to make pointer of pi
    const double* ptr = &pi; // pointer to a constant object
    // *ptr = 2; // error: point to a constant variable
    const double temp = 2;
    ptr = &temp; // ok: since address is not constant, only value remains constant; to make address constant we have to make constant pointer to constant object
    const double *const ptr2 = &pi; // constant pointer to constant object
    // *ptr2 = 2; // error: ptr2 point to a constant object
    // ptr2 = &temp; // error: ptr2 is a constant pointer

    // const pointer to plain object
    int p = 1;
    int q = 2;
    int *const ptr3 = &p;
    // ptr3 = &q; // error: ptr3 is a constant pointer

    return 0;
}