#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // by default a floating point litral is of double type
    float ex1 = 1.23;
    float ex2 = 0.23;
    // we have to add 'f' or 'F' to convert it its default type from double to float
    float ex3 = 1.23e-15f;
    // similarly we can convert it into "long double" datatype by adding 'l' or 'L' at the end of number;
    float ex4 = 1.23e10L;
    cout<<ex1<<" "<<ex2<<" "<<ex3<<" "<<ex4<<endl;
    
    return 0;
}
