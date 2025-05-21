#include<iostream>
using namespace std; 
#include<queue>

// This is a stack implementation using two queues
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    bool isEmpty() {
        return q1.empty() && q2.empty();
    }

    void push(int val) {
        // Push the element to the non-empty queue
        if (q1.empty() && q2.empty()) {
            q1.push(val);
        } else if (q1.empty()) {
            q2.push(val);
        } else {
            q1.push(val);
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Fixed: Return -1 to indicate an error
        }

        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        } else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Fixed: Return -1 to indicate an error
        }

        int element;
        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            element = q2.front();
            q1.push(q2.front()); // Restore the last element
            q2.pop();
        } else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            element = q1.front();
            q2.push(q1.front()); // Restore the last element
            q1.pop();
        }
        return element;
    }
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // Output: 30
    cout << "Popped element: " << s.pop() << endl; // Output: 30
    cout << "Top element after pop: " << s.peek() << endl; // Output: 20

    s.pop();
    s.pop();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}