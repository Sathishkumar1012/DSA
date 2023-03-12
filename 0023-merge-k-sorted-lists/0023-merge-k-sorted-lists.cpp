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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty() || lists.size() == 0) {
            return NULL;
        }
        return helper(lists, 0, lists.size() - 1);
    }

    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = start+(end-start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        while (left) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        while (right) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return head->next;
    }
};
