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
    int dfs(TreeNode* root,int m){
        if(!root) return 0;

        return (root->val>=m) + dfs(root->left,max(m,root->val)) + dfs(root->right,max(m,root->val));
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,-100);
    }
};
