#include<iostream>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data,height=1;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int getheight(Node* root) {
    if (root) {
        return root->height;
    }
    return 0;
}
int getbalance(Node* root) {
    if (root) {
        return getheight(root->left) - getheight(root->right);
    }
    return 0;
}
Node*rightrotate(Node*root){
Node*child=root->left;
Node*childright=child->right;
child->right=root;
root->left=childright;
//updateheight
root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight( child->left),getheight(child->right));
return child;
}
//left rotation
Node*leftrotate(Node*root){
Node*child=root->right;
Node*childleft=child->left;
child->left=root;
root->left=childleft;
//update height 
root->height=1+max(getheight(root->left),getheight(root->right));
child->height=1+max(getheight( child->left),getheight(child->right));
return child;
}

Node* insert(Node*root,int key){
    //root does not exist
    if(!root){
        return new Node(key);
    }
    //root exist
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    if(key>root->data){
        root->right=insert(root->right,key);
    }
    /*when the elements are duplicate*/
    else{
        return root;
    }
    //update height 
int height=1+max(getheight(root->left), getheight(root->right));
// check  balancing

   int balance=getbalance(root);  
  //left left case 
if(balance>1&&key<root->left->data){
     rightrotate(root);
    }
    //left right case 
    if(balance>1&&key>root->left->data){
        rightrotate(root);
        leftrotate(root->left);
    }
    //right right case
    if(balance<-1&&key>root->right->data){
        leftrotate(root);
    }
    //right left case
    if(balance<-1&&key<root->right->data){
        leftrotate(root->right);
        rightrotate(root); 
    }
        else{
            return root ;
        }
    }
        void preOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    
    int main() {
        Node* root = nullptr;
        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 30);
        root = insert(root, 5);
        root = insert(root, 6);
        root = insert(root, 7);
        root = insert(root, 8);
        root = insert(root, 9);
        root = insert(root, 90);
        
        cout << "Preorder traversal of the AVL tree is: ";
        preOrder(root);
        cout << endl;
    
        return 0;
    }
    
    