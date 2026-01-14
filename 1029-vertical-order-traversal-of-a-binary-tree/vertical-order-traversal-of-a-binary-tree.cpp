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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,vector<pair<int,int>>> m;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0))); //row and coloumn
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            int col=temp.second.second;
            int row=temp.second.first;
            m[col].push_back(make_pair(row,temp.first->val));
            if(temp.first->left!=NULL){
                q.push(make_pair(temp.first->left,make_pair(row+1,col-1)));
            }
            if(temp.first->right!=NULL){
                q.push(make_pair(temp.first->right,make_pair(row+1,col+1)));
            }
        }
        for(auto& i:m){
            sort(i.second.begin(),i.second.end());
        }
        for(auto i:m){
            vector<int> temp;
            for(int j=0;j<i.second.size();j++){
                temp.push_back(i.second[j].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};