/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(vector<int> &preorder, unordered_map<int,int>& mp ,int start,int end,int& preIndex){
        
        if(start>end){
            return NULL;
        }

        //first node is the root
        int nodeval=preorder[preIndex];
        preIndex++;

        TreeNode* node=new TreeNode(nodeval);
        int index=mp[nodeval];

        node->left=solve(preorder,mp,start,index-1,preIndex);
        node->right=solve(preorder,mp,index+1,end,preIndex);

        return node;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp; //postion indexes of nodes int he inorder
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        int start=0;
        int end=inorder.size()-1;
        int preIndex=0;

        return solve(preorder,mp,start,end,preIndex);

    }
};
