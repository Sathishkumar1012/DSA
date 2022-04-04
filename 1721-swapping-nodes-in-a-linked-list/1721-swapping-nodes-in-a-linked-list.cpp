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
    ListNode* swapNodes(ListNode* head, int k) {
        int i=1;
        ListNode* temp=head;
        
        // while traversing k nodes, we have n-k nodes to reach end which is the same as kth node from end.
        while(i<k) {
            temp=temp->next;
            i++;
        }
        
        ListNode* t1=temp;
        t1=t1->next;
        ListNode* t2=head;
        
        while(t1) {
            t1=t1->next;
            t2=t2->next;
        }
        swap(temp->val,t2->val);
        return head;
    }
};