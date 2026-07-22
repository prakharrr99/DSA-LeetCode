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
    int solve(TreeNode* root,int& m){
        if(root==NULL) return 0;
        int lm=max(0,solve(root->left,m));
        int rm=max(0,solve(root->right,m));

        m=max(m,max(lm+rm+root->val,max(root->val,max(lm,rm)+root->val)));
        return max(lm,rm)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int m=INT_MIN;
        solve(root,m);
        return m;
    }
};