#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};
class linklist{
    public:
    node *head = NULL;
    node *ref = NULL;
    int length = 0; // length of the given linklist
    // Add a node at the end of the linklist
    void addNode(int x){
        if(head == NULL){
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            head = ref = temp;
        }
        else{
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            ref->next = temp;
            ref = ref->next;
        }
        length++;
    }
    // Delete the first occurrences of the given node
    void deleteNode(int x){
        if(length == 0){
            cout << "Can't delete a element from an empty list!" << endl;
            return;
        }
        node *temp = head;
        if(temp->data == x){
            head = temp->next;
            length--;
            return;
        }
        while(temp != NULL && temp->next->data != x){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        length--;
    }
    // Reverses the linklist
    void reverse(){
        node* curr = head, *pre = NULL, *next;
        while(curr!= NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        head = pre;
    }
    // Print the linklist
    void printList(){
        node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

