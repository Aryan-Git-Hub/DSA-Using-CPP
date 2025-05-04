#include<iostream>
using namespace std;

// 1. Preorder(NLR)
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to create a binary tree using preorder traversal
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

// 2. Preorder(NLR)
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 2. Inorder(LNR)
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 3. Postorder(LRN)
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    cout<<"Enter the root element: ";
    Node* root = preorderBT();
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}