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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *current = new ListNode();
        ListNode *head=current;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        if (head1 != nullptr){
            current->next = head1;}
        if(head2 !=nullptr){
            current->next = head2;
        }
        return head->next;   
    }
};