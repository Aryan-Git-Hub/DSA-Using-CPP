#include<iostream>
using namespace std;

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

Node* insert(Node* root, int target) {
    if (root==NULL)
    {
        Node* temp = new Node(target);
        return temp;
    }
    if (target<root->data) root->left = insert(root->left, target);
    else root->right = insert(root->right, target);
    return root;
}

void inorder(Node* root){
    if (root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* deleteNode(Node* root, int target) {
    if(!root) return;
    if(target<root->data) {
        root->left = deleteNode(root->left, target);
        return root;
    }
    if(target>root->data) {
        root->right = deleteNode(root->right, target);
        return root;
    }
    else {
        // root->data == target
        // 1. at leaf
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // 2. single node attached
        // a) right side
        if (!root->left)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // b) left side
        if (!root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // 3. if both the side nodes attached
        Node* parent = root;
        Node* child = root->left;

        while (child->right)
        {
            child = child->right;
            parent = parent->right;
        }
        if(parent!=root){
            parent->right = child->left;
            child->left = root->left;
            child->right = root->right;
        }
        else child->right = parent->right;
        delete root;
        return child;
    }
}

bool search(Node* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    if (target < root->data) return search(root->left, target);
    else return search(root->right, target);
}

int main() {
    int n = 12;
    int arr[] = {6, 3, 17, 5, 11, 18,2, 4, 10, 12, 15, 20};
    Node* root = NULL;

    for (int i = 0; i < n; i++) root = insert(root, arr[i]);
    inorder(root);

    return 0;
}