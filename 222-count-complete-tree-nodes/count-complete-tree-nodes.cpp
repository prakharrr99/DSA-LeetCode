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
    void t(TreeNode* root,int& c){
        if(root==NULL){
            return;
        }
        c++;
        t(root->left,c);
        t(root->right,c);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int c=0;
        t(root,c);
        return c;
    }
};