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
    
    int maxDepth(TreeNode* root, int* flag) {
        if(!root) return 0;

        int l = maxDepth(root->left, flag);
        int r = maxDepth(root->right, flag);

        if(abs(l-r)>1) *flag=0;
        return 1+max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        int flag=1;
        maxDepth(root, &flag);
        return flag;
    }
};
