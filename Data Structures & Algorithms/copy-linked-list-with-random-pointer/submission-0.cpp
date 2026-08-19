/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> mp;

        Node* cp=head;

        while(cp!=nullptr){
            mp[cp]=new Node(cp->val);
            cp=cp->next;
        }

        cp=head;

        while(cp!=nullptr){
            mp[cp]->next=mp[cp->next];
            mp[cp]->random=mp[cp->random];

            cp=cp->next;

        }
        return mp[head];
    }
};
