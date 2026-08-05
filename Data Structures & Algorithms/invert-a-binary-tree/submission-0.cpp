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
    TreeNode* invertTree(TreeNode* root) {
        //using bfs
        queue<TreeNode*> q;
        q.push(root);

        if(root==NULL){
            return NULL;
        }

        while(!q.empty()){
            TreeNode* rootnode=q.front();
            q.pop();

            swap(rootnode->left,rootnode->right);

            if(rootnode->left){//if left node exist
                q.push(rootnode->left);

            }
            if(rootnode->right){
                q.push(rootnode->right);
            }

        }

        return root;

    }
};
