/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL) return NULL;
       if(root->val==p->val || root->val==q->val) return root;

       //ITERATIVE WAY  -> NO STACK SPACE
       while(root!=NULL){
        if(root->val>p->val && root->val>q->val) root=root->left;
        else if(root->val<p->val && root->val<q->val) root=root->right;
        else return root;
       }

       //RECURSIVE WAY
    //    if(root->val>p->val && root->val>q->val) root=lowestCommonAncestor(root->left,p,q);
    //    else if(root->val<p->val && root->val<q->val) root=lowestCommonAncestor(root->right,p,q);


       return root;
    }
};