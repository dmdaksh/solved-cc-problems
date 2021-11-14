#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

class linklist{
    private:
    node *head = NULL;
    node *ref = NULL;
    public:
    void addNode(int x){
        node *temp = new node;
        temp->data = x;
        temp->next = NULL;
        if(head == NULL) {
            head = ref = temp;
        }
        else{
            ref->next = temp;
            ref = ref->next;
        }
    }
    void printNode(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void sortedInsert(int x){
        node *curr = head, *pre;
        if(head == NULL){
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            head = temp;
            return;
        }
        if(curr != NULL && curr->data >= x){
            node *temp = new node;
            temp->data = x;
            temp->next = curr;
            head = temp;
            return;
        }
        while(curr != NULL && curr->data <= x){
            pre = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            pre->next = temp;
            return;
        }
        node *temp = new node;
        temp->data = x;
        temp->next = curr;
        pre->next = temp;
    }
    void del(int x){
        node *curr = head, *pre;
        
    }
};

int main(){
    linklist ll;
    ll.sortedInsert(2);
    ll.sortedInsert(10);
    ll.sortedInsert(11);
    ll.sortedInsert(3);
    ll.sortedInsert(6);
    ll.sortedInsert(8);
    // ll.printNode();
    // cout << endl;
    ll.sortedInsert(1);
    ll.printNode();
}
