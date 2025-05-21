#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data, height = 1;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int getheight(Node *root)
{
    if (root)
    {
        return root->height;
    }
    return 0;
}
int getbalance(Node *root)
{
    if (root)
    {
        return getheight(root->left) - getheight(root->right);
    }
    return 0;
}
Node *rightrotate(Node *root)
{
    Node *child = root->left;
    Node *childright = child->right;
    child->right = root;
    root->left = childright;
    // updateheight
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}
// //left rotation
Node *leftrotate(Node *root)
{
    Node *child = root->right;
    Node *childleft = child->left;
    child->left = root;
    root->right = childleft;
    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
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
Node *deleteNode(Node *root, int key)
{
    
    if (!root)
    {
        return NULL;
    }
    //left side
    if (key < root->data)
    {
        // storing the address
        root->left = deleteNode(root->left, key);
    }
    //right side
    
    
    else if(key>root->data){
        root->right =deleteNode(root->right,key);

    }
    else{
        //leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        //one child
        else if(root->left && !root->right){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        //both child exist
        else{
            //right side smallest element 
        Node*curr=root->right;
        while(curr->left){
            curr=curr->left;
        }
        //copy the value of the smallest element to the root
        root->data=curr->data;
        //delete the smallest element from the right side
        root->right=deleteNode(root->right,curr->data);
        //return the root 
        }
    }
    

//update height 
root->height = 1 + max(getheight(root->left), getheight(root->right));
//get balance factor
int balance = getbalance(root);
//left left case
if (balance > 1 && getbalance(root->left) >= 0)
    {
        return rightrotate(root);
    }
    //left right case
    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    //right right case
    if (balance < -1 && getbalance(root->right) <= 0)
    {
        return leftrotate(root);
    }
    //right left case
    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int arr[] = {3, 7, 4, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    root=deleteNode(root,4);

    cout << "Inorder Traversal of the AVL Tree: ";
    inorder(root);
    cout << endl;
    return 0;
}