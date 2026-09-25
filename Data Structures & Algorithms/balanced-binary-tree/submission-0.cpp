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
    int flag=1;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        if(abs(l-r)>1) flag=0;
        return 1+max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return flag;
    }
};
