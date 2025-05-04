#include <iostream>
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


int evaluatePostfix(const string& expression) {
    Stack s(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val1 = s.peek();
            s.pop();
            int val2 = s.peek();
            s.pop();

            switch (ch) {
                case '+':
                    s.push(val2 + val1);
                    break;
                case '-':
                    s.push(val2 - val1);
                    break;
                case '*':
                    s.push(val2 * val1);
                    break;
                case '/':
                    s.push(val2 / val1);
                    break;
            }
        }
    }
    return s.peek();
}

int main() {
    string expression;
    // cout << "Enter postfix expression: ";
    cin >> expression; // 231*+9-

    cout << "The result of the postfix expression is: " << evaluatePostfix(expression) << endl;

    return 0;
}