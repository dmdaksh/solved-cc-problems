#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x): val(x), left(NULL), right(NULL){}
};

bool univalTree(node *root, int &count){
    if(root == NULL) return true;

    bool left = univalTree(root->left, count);
    bool right = univalTree(root->right, count);

    if(left == false || right == false) return false;

    if(root->left && root->val != root->left->val) return false;
    if(root->right && root->val != root->right->val) return false;

    count++;
    return true;
}

int main(){
    int count = 0;
    node *root;
    node *ref = root = new node(0);
    ref->left = new node(1);
    ref->right = new node(0);
    ref->right->left = new node(1);
    ref->right->left->left = new node(1);
    ref->right->left->right = new node(1);
    ref->right->right = new node(0);

    univalTree(root, count);
    cout << count << endl;

}


