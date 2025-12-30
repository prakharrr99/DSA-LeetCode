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
    void count(TreeNode* root,vector<int>& r1){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            r1.push_back(root->val);
            return;
        }
        count(root->left,r1);
        count(root->right,r1);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        count(root1,r1);
        count(root2,r2);
        return r1==r2;
    }
};