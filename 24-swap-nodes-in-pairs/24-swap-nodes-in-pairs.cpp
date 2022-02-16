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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* t=head;
        head=head->next;
        ListNode* t1=head->next;
        head->next=t;
        while(t1 && t1->next) {
            ListNode* t2=t1->next->next;
            t->next=t1->next;
            t=t->next;
            t->next=t1;
            t1=t2;
            t=t->next;
        }
        t->next=t1;
        return head;
    }
};