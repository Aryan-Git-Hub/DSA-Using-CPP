#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    // Create the root node
    int x, first, second;
    queue<Node*> q;

    cout<<"Enter the root node: ";
    cin >> x;
    Node* root = new Node(x);
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left child of "<<temp->data<<": ";
        cin >> first;
        if (first!=-1)
        {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout<<"Enter the right child of "<<temp->data<<": ";
        cin >> second;
        if (second!=-1)
        {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    

    return 0;
}