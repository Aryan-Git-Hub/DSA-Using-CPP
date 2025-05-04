#include<iostream>
using namespace std;
#define MAX 100;

class Queue {
    int front, rear, size;
    int* arr;

    public:
    Queue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    bool isFull() {
        if (rear==size-1) return true;
        return false;
    }

    bool isEmpty() {
        if(front>rear) return true;
        return false;
    }

    void enqueue(int elem) {
        if (!isFull()) {
            rear++;
            arr[rear] = elem;
        } else cout<<"queue overflow";
    }


    void dequeue() {
        if(!isEmpty()) front++;
        else cout<<"queue underflow";
    }

    void peek() {
        if(!isEmpty()) cout<<arr[front];
        else cout<<"queue underflow";
    }

};

int main() {
    int n;
    cout<<"Enter the size of queue: ";
    cin>>n;
    Queue q(n);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    q.dequeue();
    q.peek();



    return 0;
}