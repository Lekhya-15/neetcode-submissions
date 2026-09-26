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
//like diameter 
class Solution {
public:
    int path=INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int l=dfs(root->left);
        l=max(0,l);
        int r=dfs(root->right);
        r=max(0,r);

        path=max(path, root->val+l+r);

        return max(root->val,root->val+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return path;
    }
};
