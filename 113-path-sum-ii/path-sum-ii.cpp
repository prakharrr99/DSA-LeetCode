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
    void f(TreeNode* root,int ts,vector<vector<int>>& ans,vector<int>& a){
        if(root==NULL) return ;
        
        if(ts-root->val==0 && root->left==NULL && root->right==NULL){
            a.push_back(root->val);
            ans.push_back(a);
            a.pop_back();
            return;
        }
        
        a.push_back(root->val);
        f(root->left,ts-root->val,ans,a);
        f(root->right,ts-root->val,ans,a);
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> a;
        f(root,targetSum,ans,a);
        return ans;
    }
};