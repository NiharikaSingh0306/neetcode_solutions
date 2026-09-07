/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include<unordered_map>

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }

        //check if already exist
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }

        //if not create new one
        Node* x=new Node(node->val);

        //push that in the map
        mp[node]=x;

        for(auto& neighbors:node->neighbors){
            x->neighbors.push_back(cloneGraph(neighbors));
        }

        return x;

        
    }
};
