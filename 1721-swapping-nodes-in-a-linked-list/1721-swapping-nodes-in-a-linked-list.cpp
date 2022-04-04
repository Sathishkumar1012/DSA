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
        int n=0;
        ListNode* temp=head;
        ListNode *temp1,*temp2;
        while(temp) {
            temp=temp->next;
            n++;
        }
        
        int i=1;
        int t1,t2;
        temp1=head;
        while(i<k) {
            temp1=temp1->next;
            i++;
        }
        
        t1=temp1->val;
        
        int m=n-k+1;
        i=1;
        temp2=head;
        while(i<m) {
            temp2=temp2->next;
            i++;
        }
        t2=temp2->val;
        swap(temp1->val,temp2->val);
        return head;
    }
};