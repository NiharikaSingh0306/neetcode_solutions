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
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;//min heap;
        ListNode* dum=new ListNode(0);
        ListNode* tail=dum;
        //push in minheap
        for(auto nodeVal:lists){
            if(nodeVal){
                pq.push(nodeVal);
            }
        }

        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();

            tail->next=curr;
            tail=tail->next;

            if(curr->next){
                pq.push(curr->next);
            }


        }
        return dum->next;;



    }
};
