#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x): val(x), left(NULL), right(NULL){}
};

class bst{
    private:
    vector<int> arr;
    int i_var = -1;
    void inorderTraversal(node *tree){
        if(tree != NULL){
            inorderTraversal(tree->left);
            arr.push_back(tree->val);
            inorderTraversal(tree->right);
        }
    }
    void bstToMinHeap(node *node){
        if(node == NULL) return;
        node->val = arr[++i_var];
        bstToMinHeap(node->left);
        bstToMinHeap(node->right);
    }
    node* copyObject(node *n){
        if(n == NULL) return NULL;
        node *newNode = new node(n->val);
        newNode->left = copyObject(n->left); 
        newNode->right = copyObject(n->right);
        return newNode; 
    }
    public:
    node *root;
    bst(){
        root = NULL;
    }
    bst(bst &obj){
        root = copyObject(obj.root);
    }
    bool isEmpty(){
        if(root == NULL) return true;
        else return false;
    }
    void insertNode(int x){
        node *newNode = new node(x);
        node *parent = NULL, *ptr  = root;
        if(!isEmpty()){
            while(ptr != NULL){
                parent = ptr;
                if(x < ptr->val) ptr = ptr->left;
                else ptr = ptr->right;
            }
            if(x < parent->val) parent->left = newNode;
            else parent->right = newNode;
        }else root = newNode;
    }
    void inorder(){
        inorderTraversal(root);
        cout << endl;
    }
    void levelOrder(){
        if(isEmpty()) return;
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            node *curr = q.front();
            cout << curr->val << " ";
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            q.pop();
        }
        cout << endl;
    }
    void convertToMinHeap(){
        inorderTraversal(root);
        bstToMinHeap(root);
    }
};

int main(){
    
}
