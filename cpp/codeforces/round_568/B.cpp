#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* partition(ListNode* A) {
    ListNode* nodepre = NULL, *node = A;
    while(node != NULL){
        ListNode *x=A, *pre= NULL;
        while(x!=node && node->val >= x->val){
            pre=x;
            x=x->next;
        }
        if(x!=node){
            nodepre->next=node->next;
            node->next=x;
            if(pre==NULL){
                A=node;
            } else
            pre->next=node;
        }
        nodepre=node;
        node=node->next;
    }
    return A;
}
int main(){
    ListNode *head, *ref;
    head = ref = new ListNode(7);
    ref->next = new ListNode(2);
    ref->next->next = new ListNode(3);
    ref->next->next->next = new ListNode(5);
    ref->next->next->next->next = new ListNode(4);
    ref->next->next->next->next->next = new ListNode(6);
    ListNode* ans = partition(head);
    while(ans!=NULL){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

}
