/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=NULL;
        ListNode* n=NULL;
        while(curr!=NULL){
            n=curr->next;
            curr->next=prev;

            prev=curr;
            curr=n;
        }
        ListNode* c1=head;
        ListNode* c2=prev;
        while(c2!=NULL){
            if(c2->val!=c1->val){
                return false;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return true;
        // stack<int>st;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(!st.empty()){
        //     if(st.top()!=temp->val){
        //         return false;
        //     }
        //     st.pop();
        //     temp=temp->next;
        // }
        // return true;
    }
};