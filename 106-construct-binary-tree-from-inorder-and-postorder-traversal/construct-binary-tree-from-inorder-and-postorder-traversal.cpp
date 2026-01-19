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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& index,int InorderStart,int InorderEnd,unordered_map<int,int>& m){
        if(index<0 || InorderStart>InorderEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[index--]);
        int position=m[root->val];
        root->right=solve(postorder,inorder,index,position+1,InorderEnd,m);
        root->left=solve(postorder,inorder,index,InorderStart,position-1,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int index=postorder.size()-1;
        TreeNode* ans=solve(postorder,inorder,index,0,inorder.size()-1,m);
        return ans;
    }
};