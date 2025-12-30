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
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
private:
    void diameter(TreeNode* root,int& dia){
        if(root==NULL) return;
        
        int h1=height(root->left);
        int h2=height(root->right);
        dia=max(dia,h1+h2);

        diameter(root->left,dia);
        diameter(root->right,dia);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=INT_MIN;
        diameter(root,dia);
        return dia;
    }
};