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
    void count(TreeNode* root,int a,int& maxi){
        if(root==NULL){
            maxi=max(maxi,a);
            return;
        }
        a=a+1;
        count(root->left,a,maxi);
        count(root->right,a,maxi);
        a=a-1;
    }
public:
    int maxDepth(TreeNode* root) {
        int maxi=INT_MIN;
        int a=0;
        count(root,a,maxi);
        return maxi;
    }
};