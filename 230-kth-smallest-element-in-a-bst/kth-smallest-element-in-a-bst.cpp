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
    void inorder(TreeNode* root,vector<int>& a){
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);
        int ans=-1;
        for(int i=0;i<a.size();i++){
            if(i==k-1) ans=a[i];
        }
        return ans;
    }
};