#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    // creating Head pointer
    Node* Head;
    Head = NULL;

    // adding elements to linked list
    int n = 5;
    Node* temp;
    int arr[5] = {34, 45,67, 97, 12};
    for (int i = 0; i < n; i++)
    {
        if (Head==NULL) Head = new Node(arr[i]);
        else {
            temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }
    
    // printing elements of linked list
    temp = Head;
    while(temp)
    {
        cout<<temp->next<<" "<<temp->data<<endl;
        temp = temp->next;
    }

    // deleting temp object
    delete temp;

    return 0;
}