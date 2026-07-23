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
    void solve(TreeNode* root,int r,int c,map<pair<int,int>,vector<int>>& m){
        if(root==NULL) return ;
        m[{c,r}].push_back(root->val);
        solve(root->left,r+1,c-1,m);
        solve(root->right,r+1,c+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> m;
        solve(root,0,0,m);
        vector<vector<int>> ans;
        vector<int> a;
        int c=INT_MAX;
        for(auto it:m){
            for(auto iit:it.second){
                cout<<iit<<" "<<endl;
            }
        }
        for(auto it:m){
            sort(it.second.begin(),it.second.end());
            if(c==INT_MAX){
                for(auto iit:it.second){
                    a.push_back(iit);
                }
                c=it.first.first;
            }
            else if(c==it.first.first){
                for(auto iit:it.second){
                    a.push_back(iit);
                }
            }
            else{
                ans.push_back(a);
                a.clear();
                c=it.first.first;
                for(auto iit:it.second){
                    a.push_back(iit);
                }
            }
        }
        ans.push_back(a);
        return ans;
    }
};