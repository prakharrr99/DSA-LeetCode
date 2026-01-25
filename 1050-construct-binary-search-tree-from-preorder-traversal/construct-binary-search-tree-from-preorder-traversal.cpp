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
    TreeNode* solve(vector<int>& preorder,int i,int j,int& p,vector<int>& in,unordered_map<int,int>& m){
        if(p>=in.size() || i>j) return NULL;

        TreeNode* temp=new TreeNode(preorder[p]);
        int id=m[preorder[p++]];
        temp->left=solve(preorder,i,id-1,p,in,m);
        temp->right=solve(preorder,id+1,j,p,in,m);
        return temp;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> in=preorder;
        sort(in.begin(),in.end());
        unordered_map<int,int> m;
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        int idx=0;
        return solve(preorder,0,in.size()-1,idx,in,m);
    }
};