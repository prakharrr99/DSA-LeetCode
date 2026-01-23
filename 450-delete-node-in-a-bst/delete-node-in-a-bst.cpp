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
    int minvalue(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL && root->left!=NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                int mini=minvalue(root->right);
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            root->left=deleteNode(root->left,key);
            return root;
        }
        return root;
    }
};