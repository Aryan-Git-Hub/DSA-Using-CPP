#include<iostream>
using namespace std;
#define MAX 100;

class Stack {
    int top;
    int size;
    int* arr;

    public:
    Stack(int size) {
        top = -1;
        this->size = size;
        arr = new int[size];
    }

    // push
    void push(int value) {
        if (top == size-1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    // pop
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // peek
    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    // isEmpty
    bool isEmpty() {
        return top==-1;
    }

    // size
    int isSize() {
        return top+1;
    }
};

int main() {
    int n = MAX;
    Stack s(n);
    
    string infix;
    cout<<"Enter Infix Expression: ";
    cin>>infix; // A*(B+C*D)+E

    // string operators = "+-*/%()";

    string postfix = "";
    for (int i=0; i<infix.length(); i++) {
        if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        } else if (infix[i] == '+' || infix[i] == '-') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/') {
            while (!s.isEmpty() && (s.peek() == '*' || s.peek() == '/')) {
                postfix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
        } else {
            postfix += infix[i];
        }
    }

    cout<<"Postfix Expression: "<<postfix<<endl;

    return 0;
}