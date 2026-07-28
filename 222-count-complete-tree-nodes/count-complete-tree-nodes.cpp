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
    int lh(TreeNode* root){
        int h=0;
        while(root!=NULL){
            root=root->left;
            h++;
        }
        return h;
    }
    int rh(TreeNode* root){
        int h=0;
        while(root!=NULL){
            root=root->right;
            h++;
        }
        return h;
    }
    int s(TreeNode* root){
        if(root==NULL) return 0;
        int l=lh(root->left);
        int r=rh(root->right);

        if(l==r){
            cout<<((1<<(1+r))-1)<<endl;
            return ((1<<(1+r))-1);
        }
        return 1+s(root->left)+s(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return s(root);
    }
};