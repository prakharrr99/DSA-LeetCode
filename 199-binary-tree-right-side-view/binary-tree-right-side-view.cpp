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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        if(root==NULL) return a;
        
        map<int,int> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> p=q.front();
            q.pop();
            if(p.first->left) q.push({p.first->left,p.second+1});
            if(p.first->right) q.push({p.first->right,p.second+1});
            m[p.second]=p.first->val;
        }
        for(auto it:m){
            a.push_back(it.second);
        }
        return a;
    }
};