#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x): val(x), left(NULL), right(NULL){}
};

bool isValidBinaryTree(node *root){
    if(root == NULL) return true;

    bool left = true, right = true;
    if(root->left != NULL) left = (root->left->val <= root->val) && isValidBinaryTree(root->left);
    if(root->right != NULL) right = (root->right->val >= root->val) && isValidBinaryTree(root->right);
    
    if(left && right) return true;
    else return false;

}


int main(){
    node *root;
    // node *ref = root = new node(0);
    // ref->left = new node(1);
    // ref->right = new node(0);
    // ref->right->left = new node(1);
    // ref->right->left->left = new node(1);
    // ref->right->left->right = new node(1);
    // ref->right->right = new node(0);
    node *ref = root = new node(4);
    ref->left = new node(2);
    ref->right = new node(6);
    ref->left->left = new node(1);
    ref->left->right = new node(3);
    ref->right->left = new node(5);
    ref->right->right = new node(7);
    if(isValidBinaryTree(root)) cout << "Yes" << endl;
    else cout << "No" << endl;

}