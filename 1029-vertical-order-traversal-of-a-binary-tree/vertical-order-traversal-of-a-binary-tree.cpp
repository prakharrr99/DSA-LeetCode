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
    void f(TreeNode* root,int c,int r,map<int,map<int,multiset<int>>>& m){
        if(root==NULL) return;
        m[c][r].insert(root->val);
        f(root->left,c-1,r+1,m);
        f(root->right,c+1,r+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>> m;
        f(root,0,0,m);
        for(auto it:m){
            vector<int> a;
            for(auto iit:it.second){
                for(auto iiit:iit.second){
                    a.push_back(iiit);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};