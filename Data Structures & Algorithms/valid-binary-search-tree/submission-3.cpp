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
//or check inorder(strictly increasing) 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LONG_MIN,LONG_MAX);
    }
    bool isvalid(TreeNode* root,long Left,long Right){
        if(!root) return 1;

        int l=isvalid(root->left,Left,root->val);
        int r=isvalid(root->right,root->val,Right);

        return l && r && root->val>Left && root->val<Right;
    }
};
