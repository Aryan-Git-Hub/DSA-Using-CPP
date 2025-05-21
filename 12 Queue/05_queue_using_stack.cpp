#include<iostream>
using namespace std;
#include<stack>

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    void push(int val) {
        s1.push(val);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; // Fixed: Return -1 to indicate an error
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int element = s2.top();
        s2.pop();
        return element; // Fixed: Removed redundant code
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Fixed: Return -1 to indicate an error
        }

        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Output: 1
    cout << "Removed element: " << q.pop() << endl; // Output: 1
    cout << "Front element after pop: " << q.peek() << endl; // Output: 2

    q.pop();
    q.pop();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}