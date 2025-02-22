#include<iostream>
using namespace std;

class Stack {
    int size;
    int top;
    char *arr;

    public:
    Stack(int n) {
        size = n;
        top = -1;
        arr = new char[size];
    }

    void push(char x) {
        if(top == size-1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }

    char peek() {
        if(top == -1) {
            // cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size-1;
    }

    void display() {
        for(int i=0; i<=top; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~Stack() {
        delete[] arr;
    }

};

int main() {
    string s = "{[()[]]}";

    Stack st(s.length());
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(s[i]);
        } else {
            if(s[i] == '}' && st.peek() == '{') {
                st.pop();
            } else if(s[i] == ']' && st.peek() == '[') {
                st.pop();
            } else if(s[i] == ')' && st.peek() == '(') {
                st.pop();
            } else {
                cout<<"Invalid Parenthesis"<<endl;
                return 0;
            }
        }
    }

    if (st.peek()==-1) {
        cout<<"Valid Parenthesis"<<endl;
    } else {
        cout<<"Invalid Parenthesis"<<endl;
    }

    return 0;
}