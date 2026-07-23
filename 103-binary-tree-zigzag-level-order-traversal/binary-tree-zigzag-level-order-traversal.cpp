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
    void lot(TreeNode* root,vector<vector<int>>& ans){
        queue<TreeNode*> q;
        q.push(root);
        int c=1;
        while(!q.empty()){
            int s=q.size();
            vector<int> t;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                t.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(c){
                c=0;
                ans.push_back(t);
            }
            else{
                c=1;
                reverse(t.begin(),t.end());
                ans.push_back(t);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        lot(root,ans);
        return ans;
    }
};