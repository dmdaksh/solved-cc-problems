#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
    node(int x): val(x), next(NULL){}
};
void printList(node *head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void frontBackSplit(node *head, node *&firstHalf, node *&secondHalf){
    node *slow = head, *fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    firstHalf = head;
    secondHalf = slow->next;
    slow->next = NULL;
}
node *sortedMerge(node *firstHalf, node *secondHalf){
    node *res = NULL;
    if(firstHalf == NULL) return secondHalf;
    else if(secondHalf == NULL) return firstHalf;
    if(firstHalf->val < secondHalf->val){
        res = firstHalf;
        res->next = sortedMerge(firstHalf->next, secondHalf);
    }else{
        res = secondHalf;
        res->next = sortedMerge(firstHalf, secondHalf->next);
    }
    return res;
}
void mergeList(node *&head){
    if(head == NULL || head->next == NULL) return;
    node *firstHalf, *secondHalf;
    frontBackSplit(head, firstHalf, secondHalf);
    mergeList(firstHalf);
    mergeList(secondHalf);
    head = sortedMerge(firstHalf, secondHalf);
}
int main(){
    node *head = NULL, *ref = NULL;
    int n;
    while(cin >> n){
        if(n == -1) break;
        if(head != NULL){
            ref->next = new node(n);
            ref = ref->next;
        }else head = ref = new node(n);
    }
    printList(head);
    mergeList(head);
    printList(head);
}

// Better Solution because it doesn't give memory exceeded due to less function calls.

// ListNode *mergeSorted(ListNode *firstHalf, ListNode *secondHalf){
//     if(firstHalf == NULL) return secondHalf;
//     else if(secondHalf == NULL) return firstHalf;
//     ListNode *head = NULL, *ref = NULL;
//     if(firstHalf->val < secondHalf->val){
//         head = firstHalf;
//         firstHalf = firstHalf->next;
//     }else{
//         head = secondHalf;
//         secondHalf = secondHalf->next;
//     }
//     ref = head;
//     while(firstHalf != NULL && secondHalf != NULL){
//         if(firstHalf->val < secondHalf->val){
//             ref->next = firstHalf;
//             firstHalf = firstHalf->next;
//         }else{
//             ref->next = secondHalf;
//             secondHalf = secondHalf->next;
//         }
//         ref = ref->next;
//     }
//     if(firstHalf != NULL) ref->next = firstHalf;
//     else if(secondHalf != NULL) ref->next = secondHalf;
//     return head;
// }
// ListNode* sortList(ListNode* head) {
//     if(head == NULL || head->next == NULL) return head;
    
//     ListNode *firstHalf, *secondHalf;
//     ListNode *slow = head, *fast = head->next;
//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             slow = slow->next;
//             fast = fast->next;
//         }
//     }
//     firstHalf = head;
//     secondHalf = slow->next;
//     slow->next = NULL;
    
//     return mergeSorted(sortList(firstHalf), sortList(secondHalf));
// }