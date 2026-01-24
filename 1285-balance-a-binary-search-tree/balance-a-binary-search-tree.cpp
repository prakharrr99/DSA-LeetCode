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
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    TreeNode* solve(int s,int e,vector<int>& a){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* temp= new TreeNode(a[mid]);
        temp->left=solve(s,mid-1,a);
        temp->right=solve(mid+1,e,a);
        return temp;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return root;

        vector<int> a;
        inorder(root,a);

        int i=0; int j=a.size()-1;
        return solve(i,j,a);
    }
};