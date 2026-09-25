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
    int depth(TreeNode* root){
        if(!root) return 0;

        int l = depth(root->left);
        int r = depth(root->right);

        return 1+max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        ld=max(ld,rd);

        return max(depth(root->left)+depth(root->right),ld);

    }
};
