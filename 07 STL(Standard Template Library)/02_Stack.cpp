#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(7);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    return 0;
}