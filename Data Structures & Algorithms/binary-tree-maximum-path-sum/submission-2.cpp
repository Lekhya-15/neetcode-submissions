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
        int r=dfs(root->right);

        if(l>0 && r>0) path=max(path, root->val+l+r);
        else if(l>0) path=max(path,root->val+l);
        else if(r>0) path=max(path,root->val+r);
        else path=max(path,root->val);

        return max(root->val,root->val+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return path;
    }
};
