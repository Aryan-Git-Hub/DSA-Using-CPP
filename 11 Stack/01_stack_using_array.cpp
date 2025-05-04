#include<iostream>
using namespace std;

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
    int n = 5;
    Stack s(n);
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    

    return 0;
}