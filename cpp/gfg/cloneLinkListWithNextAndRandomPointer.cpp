#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
Node *copyList(Node *head) {
    Node *ref = head;
    while(ref != NULL){
        Node *temp;
        temp = ref->next;
        ref->next = new Node(ref->data);
        ref->next->next = temp;
        ref = temp;
    }
    ref = head;
    while(ref != NULL){
        ref->next->arb = ref->arb? ref->arb->next:ref->arb;
        ref = ref->next->next;
    }
    ref = head;
    Node *copy = head->next, *temp = head->next;
    while(ref != NULL && temp != NULL){
        ref->next = ref->next->next;
        temp->next = temp->next?temp->next->next:temp->next;
        
        ref = ref->next;
        temp = temp->next;
        
    }
    return copy;
}