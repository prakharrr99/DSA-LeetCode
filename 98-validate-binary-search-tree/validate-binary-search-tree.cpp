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
    void inorder(TreeNode* root,vector<long long>& a){
        if(root==NULL) return ;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<long long> a;
        inorder(root,a);
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>=a[i+1]) return false;
        }
        return true;
    }
};