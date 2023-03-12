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
   struct compare{
    bool operator()(const pair<int, ListNode*>& p1, const pair<int, ListNode*>& p2) {
        return p1.first > p2.first;
    }
};

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,compare>pq;
        for(int i=0;i<n;i++) {
            if(lists[i]) {
            int value=lists[i]->val;
            pq.push(make_pair(value,lists[i]));
            }
        }
        
        ListNode* temp;
        ListNode* res=NULL;
        ListNode* mergedList=NULL;
        if(!pq.empty()) {
            temp=pq.top().second;
         //   cout<<temp->val<<endl;
            pq.pop();
            res= new ListNode(temp->val);
            mergedList=res;
            if(temp->next)
                pq.push(make_pair(temp->next->val,temp->next));
        
        while(!pq.empty()) {
            temp=pq.top().second;
            pq.pop();
            res->next=new ListNode(temp->val);
            res=res->next;
            if(temp->next)
                pq.push(make_pair(temp->next->val,temp->next));
        }
            
        }
        
        return mergedList;
    }
};