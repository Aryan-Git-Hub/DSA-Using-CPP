// Time Complexity - O(n)
// Space Complexity - O(h) = height of tree
// Worst space complexity - O(n), when height of tree = n
#include<iostream>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* preorderBT() {
    int x;
    cin>>x;
    if (x==-1) return NULL;
    
    Node* temp = new Node(x);
    cout<<"Enter the left child of "<<x<<": ";
    temp->left = preorderBT();
    cout<<"Enter the right child of "<<x<<": ";
    temp->right = preorderBT();
    return temp;
}

int main() {
    cout<<"Enter the root element: ";
    Node* root = preorderBT();

    return 0;
}