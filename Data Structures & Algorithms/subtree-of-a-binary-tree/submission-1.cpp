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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p || !q) return 0;

        int l=isSameTree(p->left,q->left);
        int r=isSameTree(p->right,q->right);
        if(l && r && (p->val == q->val)) return 1;
        else return 0;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return 1;
        if(!root) return 0;

        if(isSameTree(root,subRoot)) return 1;
        else{
            int l=isSubtree(root->left,subRoot);
            int r=isSubtree(root->right,subRoot);
            return l || r;
        }
    }
};
