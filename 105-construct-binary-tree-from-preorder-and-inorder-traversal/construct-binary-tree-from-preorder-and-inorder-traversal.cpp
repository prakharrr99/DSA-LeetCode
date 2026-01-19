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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& index,int InorderStart,int InorderEnd,unordered_map<int,int>& m){
        if(index>=preorder.size() || InorderStart>InorderEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[index++]);
        int position=m[root->val];
        root->left=solve(preorder,inorder,index,InorderStart,position-1,m);
        root->right=solve(preorder,inorder,index,position+1,InorderEnd,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int index=0;
        TreeNode* ans=solve(preorder,inorder,index,0,inorder.size()-1,m);
        return ans;
    }
};