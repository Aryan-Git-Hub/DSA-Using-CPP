// The type of string litral is "array of the appropriate number of const characters", i.e. const char[]
// Another definitionn is i.e. const char*
// we cannot modify any character or value in string litrals
#include<iostream>
using namespace std;

int main() {
    const char a[5] = "Zeno";
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;
    cout<<a[2]<<endl;
    cout<<a[3]<<endl;
    cout<<int(a[4])<<endl<<endl; // NULL character

    // Another way using pointer to const char
    const char* p = "Zeno";
    cout<<*(p)<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(p+2)<<endl;
    cout<<*(p+3)<<endl;
    cout<<int(*(p+4))<<endl<<endl; // NULL character

    // we cannot modify string in above two methods because of constant in nature
    // To modify string, we must copy the characters into an array:
    char q[] = "Zeno";
    q[0] = 'R';
    cout<<*(q)<<endl;
    cout<<*(q+1)<<endl;
    cout<<*(q+2)<<endl;
    cout<<*(q+3)<<endl;
    cout<<int(*(q+4))<<endl<<endl; // NULL character

    char alpha[] = "Aryan" " Jain"
                   " is a good boy";
    // Long strings can be broken by whitespace to make the program text neater, the compiler will concatinate adjacent strings, so alpha is equivalent to "AryanJain"
    cout<<alpha<<endl<<endl;

    // A string with the prefix L, such as L"angst", is a string of wide characters, its type is const wchar_t[]
    const wchar_t wide_car[6] = L"angst";
    for (int i = 0; i < 5; i++)
    {
        cout<<char(*(wide_car+i))<<endl;
    }
    cout<<int(*(wide_car+5))<<endl<<endl;
    
    // character array or pointer ko print krne se address nhi deta puri array print kr deta hai jb tk use null character('\0') nhi mil jaata
    cout<<a<<" "<<p<<" "<<q<<endl;
    // Warning:- to make string, use method of array instead of character pointer method because if we make pointer then there may be a chance to not get any null character
    char temp = 'z';
    char* r = &temp;
    cout<<temp<<endl;


    return 0;
}