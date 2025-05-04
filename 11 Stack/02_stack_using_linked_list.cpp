#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class Stack {
    Node* top;
    int size;

    public:
    Stack() {
        top = NULL;
        size = 0;
    }

    // push
    void push(int value) {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
        size++;
    }

    // pop
    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // peek
    int peek() {
        if (!top) return -1;
        return top->data;
    }

    // isEmpty
    bool isEmpty() {
        return top==NULL;
    }

    // size
    int isSize() {
        return size;
    }
};

int main() {
    

    return 0;
}