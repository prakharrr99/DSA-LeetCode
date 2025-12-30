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
    void count(TreeNode* root,int a,int& m){
        if(root==NULL){
            m=max(m,a);
            return;
        }
        a=a+1;
        count(root->left,a,m);
        count(root->right,a,m);
        a=a-1;
    }
private:
    void diameter(TreeNode* root,int& dia){
        if(root==NULL) return;
        
        int a=0; int h1=INT_MIN;
        count(root->left,a,h1);
        int b=0; int h2=INT_MIN;
        count(root->right,b,h2);
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