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
    int count(TreeNode* root){
        if(root==NULL) return 0;
        
        return 1+count(root->left) + count(root->right);
    }
    bool isCT(TreeNode* root,int c,int i){
        if(root==NULL) return true;
        if(i>=c) return false; // do dry run samaj aayega 
        else{
            bool l=isCT(root->left,c,2*i+1);
            bool r=isCT(root->right,c,2*i+2);
            return (l && r);
        }
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int c=count(root);
        int i=0;
        if(isCT(root,c,i)) return true;
        return false;
    }
};