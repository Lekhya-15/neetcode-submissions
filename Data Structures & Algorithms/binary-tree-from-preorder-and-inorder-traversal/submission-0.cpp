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
    unordered_map<int,int> map;
    int ind=0;
    TreeNode* dfs(vector<int>& preorder,int l,int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = dfs(preorder,l,map[root->val]-1);
        root->right = dfs(preorder,map[root->val]+1,r);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() && !inorder.size()) return nullptr;

        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return dfs(preorder,0,inorder.size()-1);
    }
};
