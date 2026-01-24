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
        if(root==NULL) return ;
        
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
        return;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        vector<int> a;
        inorder(root,a);
        int i=0; int j=a.size()-1;
        while(j>i){
            if(k==a[i]+a[j]) return true;
            else if(a[i]+a[j]<k) i++;
            else j--;
        }
        return false;
    }
};