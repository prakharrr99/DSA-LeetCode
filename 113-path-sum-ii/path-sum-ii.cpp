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
private:
    void solve(TreeNode* root, int targetSum,vector<vector<int>>& ans,vector<int> a){
        if(root==NULL) return ;
        a.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum-root->val==0) ans.push_back(a);
            return ;
        }
        solve(root->left,targetSum-root->val,ans,a);
        solve(root->right,targetSum-root->val,ans,a);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        vector<int> a;

        solve(root,targetSum,ans,a);
      
        return ans;
    }
};