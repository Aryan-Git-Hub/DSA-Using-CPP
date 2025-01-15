// enum is user-defined datatype, in which we can range the size of object
#include<iostream>
using namespace std;

// default value of dark = 0  and light = 1
enum e1 {dark, light};              // range 0:1
enum e2 {a = 3, b = 9};             // range 0:15
enum e3 {min = -10, max = 1000000}; // range -1048576:1048576 (-(n+1):n), since -(n+1) is the 2nd complement of n

int main() {
    cout<<sizeof(e3)<<", less than or equal to sizeof(int) = 4 but cannot be greater than 4 becaue enumeration works with integers";

    return 0;
}